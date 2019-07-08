/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 16:35:31 by anorman           #+#    #+#             */
/*   Updated: 2019/07/01 15:39:37 by anorman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	st_prenewline(t_list **start, t_bmark *place)
{
	char	*temp;
	int		linelen;

	temp = ft_strchr(place->red, '\n');
	linelen = ft_strlen(place->red) - ft_strlen(temp);
	if (!(*start = ft_lstnew(place->red, linelen + 1)))
		return (-2);
	ft_memcpy(&(*start)->content[linelen], "\0", 1);
	if (!(temp = ft_strsub(temp, 1, ft_strlen(temp) - 1)))
		return (-2);
	free(place->red);
	place->red = temp;
	if (place->red && (*start)->content)
		return (place->fd);
	else
		return (-1);
}

static int	st_lstfill(const int fd, t_list **start, t_bmark *place)
{
	t_list	*nw;
	char	*str;
	int		red;
	int		len;

	len = 0;
	nw = NULL;
	if (!(str = (char *)malloc((BUFF_SIZE + 1) * sizeof(char))))
		return (-2);
	while (!len && (red = (int)read(fd, str, BUFF_SIZE)) > 0)
	{
		str[red] = '\0';
		if (ft_strchr(str, '\n'))
			len = ft_strlen((ft_strchr(str, '\n')));
		if (!(nw = ft_lstnew(str, red - len + 1)))
			place->fd = -2;
		ft_lstaddend(start, nw);
		ft_memcpy(&(nw->content[red - len]), "\0", 1);
		if (len)
			place->red = ft_strsub(ft_strchr(str, '\n'), 1, len - 1);
	}
	free(str);
	if (red == -1)
		return ((place->fd = -2));
	return (red == 0 && !(*start) ? -1 : fd);
}

/*
** returns fd for progress or -1 for finished; -2 for error
** puts the first line into a t_list and the unused read part
** into place->content
*/

t_bmark		*st_regplace(const int fd, t_bmark **bookmark)
{
	t_bmark		*place;

	if (!(*bookmark))
	{
		if (!(*bookmark = (t_bmark *)malloc(sizeof(t_bmark))))
			return (NULL);
		(*bookmark)->fd = fd;
		(*bookmark)->red = NULL;
		(*bookmark)->next = NULL;
		return (*bookmark);
	}
	else if (*bookmark)
	{
		place = *bookmark;
		while (place && place->fd != fd)
			place = place->next;
		if (place)
			return (place);
	}
	if (!(place = (t_bmark *)malloc(sizeof(t_bmark))))
		return (NULL);
	place->fd = fd;
	place->red = NULL;
	ft_lstadd((t_list **)bookmark, (t_list *)place);
	return (*bookmark);
}

/*
** returns the place matching the fd or makes one if not found
** returns NULL for failed to make memory
*/

int			st_cleanup(t_bmark **bm, t_bmark *pl, t_list **lst)
{
	ft_lstdel(lst);
	if (pl->fd == -1 && (!pl->red || !pl->red[0]))
	{
		ft_lstdelmid((t_list **)bm, (t_list *)pl);
		return (0);
	}
	else if (pl->fd == -2)
	{
		ft_lstdelmid((t_list **)bm, (t_list *)pl);
		return (-1);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_bmark	*bookmark;
	t_bmark			*place;
	t_list			*lst;

	if (fd < 0 || !line || read(fd, NULL, 0) == -1)
		return (-1);
	if (!(place = st_regplace(fd, &bookmark)))
		return (-1);
	lst = NULL;
	if (place->red && place->red[0] && !ft_strchr(place->red, '\n'))
	{
		if (!(lst = ft_lstnew(place->red, ft_strlen(place->red) + 1)))
			place->fd = -2;
		ft_strdel(&place->red);
	}
	if (place->red && ft_strchr(place->red, '\n'))
		place->fd = st_prenewline(&lst, place);
	else if (place->fd != -2)
		place->fd = st_lstfill(fd, &lst, place);
	if (place->fd != -2)
		if (!(*line = ft_lstcat(lst)))
			place->fd = -2;
	if (place->fd == -1 && (!*line || !(*line)[0]))
		ft_strdel(line);
	return (st_cleanup(&bookmark, place, &lst));
}

/*
** bookmark is the list of in progress reads.
** place->content is unused but read content
** place->content_size is the fd associated or -1 for finished
** returns 1 for read; 0 for end file; -1 for error
*/
