/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lajudy <lajudy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 00:43:53 by lajudy            #+#    #+#             */
/*   Updated: 2022/02/10 13:34:36 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	close_minirt(void)
{
	kd_free_all();
	printf("\nExit\n");
	exit(0);
}

void	reset_game(t_scene *scene)
{
	(void)scene;
}

static t_bool	toggle(t_bool *b)
{
	if (!*b)
		*b = TRUE;
	else
		*b = FALSE;
	return (*b);
}

static int	key_hook(int key, t_scene *scene)
{
	if (key == KEY_ESC)
		close_minirt();
	else if (key == KEY_R)
	{
		scene->view++;
		if (scene->view >= 7 || scene->view < 0)
			scene->view = 0;
//		reset_game(mlx);
	} else if (key == KEY_ENTER)
		scene->play = TRUE;
//		next_level(mlx);
//	if (check_move(key, mlx) && scene->hud)
//		scene->hud = kd_free(scene->hud);
	else if (key == KEY_OPENBRACKET && scene->view)
		scene->camera->fov -= 5;
	else if (key == KEY_OPENBRACKET && !scene->view)
		scene->camera->zoom -= 5;
	else if (key == KEY_CLOSEBRACKET && scene->view)
		scene->camera->fov += 5;
	else if (key == KEY_CLOSEBRACKET && !scene->view)
		scene->camera->zoom += 5;
	else if (key == KEY_UP)
		scene->camera->rotate.v += 5;
	else if (key == KEY_DOWN)
		scene->camera->rotate.v -= 5;
	else if (key == KEY_LEFT)
		scene->camera->rotate.u -= 5;
	else if (key == KEY_RIGHT)
		scene->camera->rotate.u += 5;
	else if (key == KEY_W)
		scene->camera->position = matrix3_addition(scene->camera->position, vector3_multiply(vector3_rotate_yx(scene->camera->orient, scene->camera->rotate), 5));
	else if (key == KEY_S)
		scene->camera->position = matrix3_addition(scene->camera->position, vector3_multiply(vector3_rotate_yx(scene->camera->orient, scene->camera->rotate), -5));
	else if (key == KEY_A)
	{
		t_vector2	rotate;
		rotate.u = scene->camera->rotate.u - 90;
		rotate.v = 0;
		scene->camera->position = matrix3_addition(scene->camera->position, vector3_multiply(vector3_rotate_yx(scene->camera->orient, rotate), 5));
	}
	else if (key == KEY_D)
	{
		t_vector2	rotate;
		rotate.u = scene->camera->rotate.u + 90;
		rotate.v = 0;
		scene->camera->position = matrix3_addition(scene->camera->position, vector3_multiply(vector3_rotate_yx(scene->camera->orient, rotate), 5));
	}
	else if (key == KEY_Q)
	{
		t_vector2	rotate;
		rotate.u = scene->camera->rotate.u;
		rotate.v = scene->camera->rotate.v - 90;
		scene->camera->position = matrix3_addition(scene->camera->position, vector3_multiply(vector3_rotate_yx(scene->camera->orient, rotate), 5));
	}
	else if (key == KEY_E)
	{
		t_vector2	rotate;
		rotate.u = scene->camera->rotate.u;
		rotate.v = scene->camera->rotate.v + 90;
		scene->camera->position = matrix3_addition(scene->camera->position, vector3_multiply(vector3_rotate_yx(scene->camera->orient, rotate), 5));
//		printf("c %f %f %f -> %f %f %f\n", )
	}
	else if (key == KEY_1)
		scene->maxquality = 1;
	else if (key == KEY_2)
		scene->maxquality = 2;
	else if (key == KEY_3)
		scene->maxquality = 3;
	else if (key == KEY_4)
		scene->maxquality = 4;
	else if (key == KEY_5)
		scene->maxquality = 5;
	else if (key == KEY_6)
		scene->minquality = kd_max(scene->width, scene->height) / 240;
	else if (key == KEY_7)
		scene->minquality = kd_max(scene->width, scene->height) / 120;
	else if (key == KEY_8)
		scene->minquality = kd_max(scene->width, scene->height) / 60;
	else if (key == KEY_9)
		scene->minquality = kd_max(scene->width, scene->height) / 40;
	else if (key == KEY_0)
		scene->minquality = kd_max(scene->width, scene->height) / 20;
	else if (key == KEY_Z)
		toggle(&scene->no_shadows);
	else if (key == KEY_X)
		toggle(&scene->one_light);
	else if (key == KEY_C)
		toggle(&scene->no_lights);
	else if (key == KEY_V)
		toggle(&scene->no_specular);
	else if (key == KEY_B)
		toggle(&scene->checkerboard);
	else if (key == KEY_N)
		toggle(&scene->bump);
	else if (key == KEY_F)
		reset_camera(scene);
	else if (key == KEY_I)
		scene->light->position.z += 5;
	else if (key == KEY_J)
		scene->light->position.x -= 5;
	else if (key == KEY_K)
		scene->light->position.z -= 5;
	else if (key == KEY_L)
		scene->light->position.x += 5;
	else if (key == KEY_U)
		scene->light->position.y -= 5;
	else if (key == KEY_O)
		scene->light->position.y += 5;
	if (key == KEY_1 || key == KEY_2 || key == KEY_3 || key == KEY_4 || key == KEY_5)
	{
		if (scene->everynframe < scene->maxquality)
			scene->everynframe = scene->maxquality;
		scene->idle = 0;

	}
	else if (key == KEY_U || key == KEY_O || key == KEY_I || key == KEY_J || key == KEY_K || key == KEY_L || key == KEY_Z || key == KEY_X || key == KEY_C || key == KEY_V || key == KEY_B || key == KEY_N || key == KEY_F || key == KEY_W || key == KEY_S || key == KEY_A || key == KEY_D || key == KEY_Q || key == KEY_E || key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT || key == KEY_RIGHT || key == KEY_R || key == KEY_OPENBRACKET || key == KEY_CLOSEBRACKET)
	{
		scene->everynframe = scene->minquality;
		scene->rays_set = FALSE;
		scene->idle = 0;
	}
	printf("key %d\n", key);
	return (0);
}

// static int	mouse_hook(int button, int x, int y, t_mlx *mlx)
// {
// t_vector3		proportion;
// t_vector3	direction;

// proportion.x = (x - mlx->win_w / (double)2) / mlx->win_w * (double)2;
// proportion.y = (y - mlx->win_h / (double)2) / mlx->win_w * (double)2;
// proportion.z = 1;
// direction = vector3_normalise(proportion);
// printf("x %d, proportion.x %f, y %d, proportion.y %f\n", x, proportion.x, y, proportion.y);
// printf("direction.x %f, direction.y %f, direction.z %f\n", direction.x, direction.y, direction.z);
// (void)button;
// 	return (0);
// }

static t_img	*new_image(char *path, t_scene *scene)
{
	t_img	*img;

	img = kd_calloc(1, sizeof(t_img));
	if (!img)
		ft_error(-1);
	img->img = mlx_xpm_file_to_image(scene->mlx, path, &img->width, &img->height);
	if (!img->img)
		ft_error(-1);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->bytes_per_line, &img->endian);
	if (!img->addr)
		ft_error(-1);
	return (img);
}

int	main(int argc, char **argv)
{
	t_scene *scene;

	if (argc == 1 || invalid_filename(argv[1]))
		ft_error(1);
	scene = scene_init(argv[1]);
	while (--argc > 1)
	{
		if (argv[argc][0] == '-' && kd_strchr(argv[argc], 's'))
			scene->no_shadows = TRUE;
		if (argv[argc][0] == '-' && kd_strchr(argv[argc], 'l'))
			scene->one_light = TRUE;
		if (argv[argc][0] == '-' && kd_strchr(argv[argc], 'L'))
			scene->no_lights = TRUE;
	}
	scene->hud = kd_strf("%s", "Press AWSD to move");
	scene->view = 5;
	scene->bumpmap = new_image("sprites/plane_bump_map.xpm", scene);
	scene->texturemap = new_image("sprites/textureground.xpm", scene);
	printf("bonus = %d\n", BONUS);
	scene->maxquality = 1;
	scene->minquality = kd_max(scene->width, scene->height) / 20;
	scene->everynframe = scene->minquality;
	scene->rays = kd_calloc(scene->width * scene->height, sizeof(t_ray));
	mlx_loop_hook(scene->mlx, render_next_frame, scene);
	mlx_hook(scene->window, 2, (1L << 0), key_hook, scene);
	mlx_hook(scene->window, 17, 0, close_minirt, scene);
	// mlx_mouse_hook(scene->window, mouse_hook, scene);
	mlx_loop(scene->mlx);
}
