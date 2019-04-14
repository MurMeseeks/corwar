/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <mmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 18:13:50 by mmcclure          #+#    #+#             */
/*   Updated: 2019/04/14 19:33:47 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/visu.h"

static void		init_win_consts(t_window *window)
{
	WIN_QUIT = 0;
	WIN_STATUS = STAT_START;
	WIN_WID = SCREEN_WIDTH;
	WIN_HEIG = SCREEN_HEIGHT;
	WIN_SPEED = 50;
	FONT_COLOR = (SDL_Color){COL_WHITE};
}

t_window		*init_win(void)
{
	t_window	*window;

	if (!(window = (t_window*)malloc(sizeof(t_window))))
		return (NULL);
	init_win_consts(window);
	if (SDL_Init(SDL_INIT_VIDEO) < 0 ||
						SDL_Init(SDL_INIT_AUDIO) < 0 || TTF_Init() < 0)
	{
		ft_printf("Init_Error: %s\n", SDL_GetError());
		return (NULL);
	}
	WIN_WIN = SDL_CreateWindow("Vizualizer", SDL_WINDOWPOS_UNDEFINED,\
	SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
	if (WIN_WIN == NULL)
	{
		ft_printf("Init_Window_Error: %s\n", SDL_GetError());
		return (NULL);
	}
	WIN_REND = SDL_CreateRenderer(WIN_WIN, -1, SDL_RENDERER_ACCELERATED);
	if (WIN_REND == NULL)
	{
		ft_printf("Init_Renderer_Error: %s\n", SDL_GetError());
		return (NULL);
	}
	return (window);
}
