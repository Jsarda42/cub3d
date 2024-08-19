/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:58:17 by ftanon            #+#    #+#             */
/*   Updated: 2024/08/19 18:57:43 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "/home/ftanon/Desktop/milestone2/so_long/solong/minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <X11/X.h>
# include <X11/keysym.h>

#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24

typedef struct s_mlx
{
	void			*mlx_p;
	void			*img;
	void			*win_ptr;
	double posX;
	double posY;
	double dirX; 
	double dirY;
	double planeX;
	double planeY;
	double time;
	double oldTime;
	double cameraX ;
	double rayDirX;
	double rayDirY;

	int mapX;
	int mapY;


	double sideDistX;
	double sideDistY;

	double deltaDistX;
	double deltaDistY;
	double perpWallDist;


	int stepX;
	int stepY;

	int hit;
	int side;
	int lineHeight;

	int drawStart;
	int drawEnd;
	int color;
} t_mlx;

// typedef struct {
//     double x, y;      // Player position
//     double dirX, dirY; // Direction vector
//     double planeX, planeY; // Camera plane
// } Player;

// Player player = {22, 12, -1.0, 0.0, 0.0, 0.66};

// int worldMap[mapWidth][mapHeight]=
// {
//   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
//   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
//   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
// };

// void draw_vertical_line(void *mlx, void *win, int x, int start, int end, int color) {
//     for (int y = start; y <= end; y++) {
//         mlx_pixel_put(mlx, win, x, y, color);
//     }
// }

// void raycasting(void *mlx, void *win) {
//     for (int x = 0; x < screenWidth; x++) {
//         // Calculate ray position and direction
//         double cameraX = 2 * x / (double)screenWidth - 1; // x-coordinate in camera space
//         double rayDirX = player.dirX + player.planeX * cameraX;
//         double rayDirY = player.dirY + player.planeY * cameraX;

//         // Map position
//         int mapX = (int)player.x;
//         int mapY = (int)player.y;

//         // Length of ray from current position to next x or y-side
//         double sideDistX;
//         double sideDistY;

//         // Length of ray from one x or y-side to next x or y-side
//         double deltaDistX = fabs(1 / rayDirX);
//         double deltaDistY = fabs(1 / rayDirY);
//         double perpWallDist;

//         // Direction to step in x and y (either +1 or -1)
//         int stepX;
//         int stepY;

//         int hit = 0; // Was there a wall hit?
//         int side;    // Was a NS or a EW wall hit?

//         // Calculate step and initial sideDist
//         if (rayDirX < 0) {
//             stepX = -1;
//             sideDistX = (player.x - mapX) * deltaDistX;
//         } else {
//             stepX = 1;
//             sideDistX = (mapX + 1.0 - player.x) * deltaDistX;
//         }
//         if (rayDirY < 0) {
//             stepY = -1;
//             sideDistY = (player.y - mapY) * deltaDistY;
//         } else {
//             stepY = 1;
//             sideDistY = (mapY + 1.0 - player.y) * deltaDistY;
//         }

//         // Perform DDA (Digital Differential Analyzer)
//         while (hit == 0) {
//             // Jump to next map square, either in x-direction, or in y-direction
//             if (sideDistX < sideDistY) {
//                 sideDistX += deltaDistX;
//                 mapX += stepX;
//                 side = 0;
//             } else {
//                 sideDistY += deltaDistY;
//                 mapY += stepY;
//                 side = 1;
//             }
//             // Check if ray has hit a wall
//             if (worldMap[mapX][mapY] > 0) hit = 1;
//         }

//         // Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
//         if (side == 0) perpWallDist = (sideDistX - deltaDistX);
//         else           perpWallDist = (sideDistY - deltaDistY);

//         // Calculate height of line to draw on screen
//         int lineHeight = (int)(screenHeight / perpWallDist);

//         // Calculate lowest and highest pixel to fill in current stripe
//         int drawStart = -lineHeight / 2 + screenHeight / 2;
//         if(drawStart < 0) drawStart = 0;
//         int drawEnd = lineHeight / 2 + screenHeight / 2;
//         if(drawEnd >= screenHeight) drawEnd = screenHeight - 1;

//         // Choose wall color (we use simple red color)
// 	// 	 int color;
// 	//   switch(worldMap[mapX][mapY])
//     //   {
//     //     case 1:  color = 0xFF0000;  break; //red
//     //     case 2:  color = 0x00FF00;  break; //green
//     //     case 3:  color = 0x0000FF;   break; //blue
//     //     case 4:  color = 0xFFFFFF;  break; //white
//     //     default: color = 0xFFFF00; break; //yellow
//     //   }
//         int color = 0xFF0000;
//         if (side == 1) color = 0x0000FF; // Darker for y-side

//         // Draw the vertical line
//         draw_vertical_line(mlx, win, x, drawStart, drawEnd, color);
//     }
// }

// int key_hook(int keycode, t_mlx *mlx) {
//     // if (keycode == 65307) { // ESC key to exit
//     //     mlx_destroy_window(param, param);
//     //     exit(0);
//     // }
//     double moveSpeed = 0.1;
//     double rotSpeed = 0.05;
//     if (keycode == 119) { // W key for forward
//         if (!worldMap[(int)(player.y)][(int)(player.x + player.dirX * moveSpeed)]) player.x += player.dirX * moveSpeed;
//         if (!worldMap[(int)(player.y + player.dirY * moveSpeed)][(int)(player.x)]) player.y += player.dirY * moveSpeed;
//     }
//     if (keycode == 115) { // S key for backward
//         if (!worldMap[(int)(player.y)][(int)(player.x - player.dirX * moveSpeed)]) player.x -= player.dirX * moveSpeed;
//         if (!worldMap[(int)(player.y - player.dirY * moveSpeed)][(int)(player.x)]) player.y -= player.dirY * moveSpeed;
//     }
//     if (keycode == 97) { // A key to rotate left
//         double oldDirX = player.dirX;
//         player.dirX = player.dirX * cos(-rotSpeed) - player.dirY * sin(-rotSpeed);
//         player.dirY = oldDirX * sin(-rotSpeed) + player.dirY * cos(-rotSpeed);
//         double oldPlaneX = player.planeX;
//         player.planeX = player.planeX * cos(-rotSpeed) - player.planeY * sin(-rotSpeed);
//         player.planeY = oldPlaneX * sin(-rotSpeed) + player.planeY * cos(-rotSpeed);
// 		raycasting(mlx->mlx_p, mlx->win_ptr);
//     }
//     if (keycode == 100) { // D key to rotate right
//         double oldDirX = player.dirX;
//         player.dirX = player.dirX * cos(rotSpeed) - player.dirY * sin(rotSpeed);
//         player.dirY = oldDirX * sin(rotSpeed) + player.dirY * cos(rotSpeed);
//         double oldPlaneX = player.planeX;
//         player.planeX = player.planeX * cos(rotSpeed) - player.planeY * sin(rotSpeed);
//         player.planeY = oldPlaneX * sin(rotSpeed) + player.planeY * cos(rotSpeed);
// 		raycasting(mlx->mlx_p, mlx->win_ptr);
//     }
//     return 0;
// }



// int main() {
// 	t_mlx *mlx;

// 	mlx = malloc(sizeof(t_mlx));
//     mlx->mlx_p = mlx_init();
//     mlx->win_ptr = mlx_new_window(mlx, screenWidth, screenHeight, "Raycasting");

//     mlx_key_hook(mlx->mlx_p, key_hook, mlx); // Hook for key events

//     while (1) {
//         // Clear screen (in MiniLibX, you have to manually clear or redraw)
//         mlx_clear_window( mlx->mlx_p, mlx->win_ptr);

//         // Render the scene using raycasting
//         raycasting( mlx->mlx_p, mlx->win_ptr);

//         // Handle events
//         mlx_loop(mlx->mlx_p);
//     }

//     return 0;
// }

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void draw_vertical_line(void *mlx, void *win, int x, int start, int end, int color) {
    for (int y = start; y <= end; y++) {
        mlx_pixel_put(mlx, win, x, y, color);
    }
}

void raycasting(t_mlx *mlx)
{
 for(int x = 0; x < screenWidth; x++)
{

		mlx->cameraX = 2 * x / (double)screenWidth - 1;
		mlx->rayDirX = mlx->dirX + mlx->planeX * mlx->cameraX;
		mlx->rayDirY = mlx->dirY + mlx->planeY * mlx->cameraX;

		mlx->mapX = (int)mlx->posX;
		mlx->mapY = (int)mlx->posY;

		mlx->deltaDistX = fabs(1 / mlx->rayDirX);
		mlx->deltaDistY = fabs(1 / mlx->rayDirY);

		mlx->hit = 0;

		if (mlx->rayDirX < 0)
		{
			mlx->stepX = -1;
			mlx->sideDistX = (mlx->posX - mlx->mapX) * mlx->deltaDistX;
		}
		else
		{
			mlx->stepX = 1;
			mlx->sideDistX = (mlx->mapX + 1.0 - mlx->posX) * mlx->deltaDistX;
		}
		if (mlx->rayDirY < 0)
		{
			mlx->stepY = -1;
			mlx->sideDistY = (mlx->posY - mlx->mapY) * mlx->deltaDistY;
		}
		else
		{
			mlx->stepY = 1;
			mlx->sideDistY = (mlx->mapY + 1.0 - mlx->posY) * mlx->deltaDistY;
		}

		while (mlx->hit == 0)
		{
			if (mlx->sideDistX < mlx->sideDistY)
			{
				mlx->sideDistX += mlx->deltaDistX;
				mlx->mapX += mlx->stepX;
				mlx->side = 0;
			}
			else
			{
				mlx->sideDistY += mlx->deltaDistY;
				mlx->mapY += mlx->stepY;
				mlx->side = 1;
			}
			if (worldMap[mlx->mapX][mlx->mapY] > 0)
				mlx->hit = 1;
		}

		if (mlx->side == 0)
			mlx->perpWallDist = (mlx->sideDistX - mlx->deltaDistX);
		else
			mlx->perpWallDist = (mlx->sideDistY - mlx->deltaDistY);

     mlx->lineHeight = (int)(screenHeight / mlx->perpWallDist);

      mlx->drawStart = -mlx->lineHeight / 2 + screenHeight / 2;
      if(mlx->drawStart < 0)mlx->drawStart = 0;
      mlx->drawEnd = mlx->lineHeight / 2 + screenHeight / 2;
      if(mlx->drawEnd >= screenHeight)mlx->drawEnd = screenHeight - 1;

	  switch(worldMap[mlx->mapX][mlx->mapY])
      {
        case 1:  mlx->color = 0xFF0000;  break; //red
        case 2:  mlx->color = 0x00FF00;  break; //green
        case 3:  mlx->color = 0x0000FF;   break; //blue
        case 4:  mlx->color = 0xFFFFFF;  break; //white
        default: mlx->color = 0xFFFF00; break; //yellow
      }

      if (mlx->side == 1) {mlx->color = mlx->color / 2;}

	draw_vertical_line(mlx->mlx_p, mlx->win_ptr, x, mlx->drawStart, mlx->drawEnd, mlx->color);
}
}

int key_hook(int keycode, t_mlx *mlx) {
    // if (keycode == 65307) { // ESC key to exit
    //     mlx_destroy_window(param, param);
    //     exit(0);
    // }
    double moveSpeed = 0.1;
    double rotSpeed = 0.1;
    if (keycode == 119) { // W key for forward
        if(!worldMap[(int)(mlx->posX + mlx->dirX * moveSpeed)][(int)mlx->posY]) mlx->posX += mlx->dirX * moveSpeed;
      if(!worldMap[(int)mlx->posX][(int)(mlx->posY + mlx->dirY * moveSpeed)]) mlx->posY += mlx->dirY * moveSpeed;
	  mlx_clear_window(mlx->mlx_p, mlx->win_ptr);
	  raycasting(mlx);

    }
    if (keycode == 115) { // S key for backward
        if(!worldMap[(int)(mlx->posX - mlx->dirX * moveSpeed)][(int)mlx->posY]) mlx->posX -= mlx->dirX * moveSpeed;
      if(!worldMap[(int)mlx->posX][(int)(mlx->posY - mlx->dirY * moveSpeed)]) mlx->posY -= mlx->dirY * moveSpeed;
	  mlx_clear_window(mlx->mlx_p, mlx->win_ptr);
	  raycasting(mlx);
    }
    if (keycode == 97) { // A key to rotate left
         double oldDirX = mlx->dirX;
      mlx->dirX = mlx->dirX * cos(rotSpeed) - mlx->dirY * sin(rotSpeed);
      mlx->dirY = oldDirX * sin(rotSpeed) + mlx->dirY * cos(rotSpeed);
      double oldPlaneX = mlx->planeX;
      mlx->planeX = mlx->planeX * cos(rotSpeed) - mlx->planeY * sin(rotSpeed);
      mlx->planeY = oldPlaneX * sin(rotSpeed) + mlx->planeY * cos(rotSpeed);
	  mlx_clear_window(mlx->mlx_p, mlx->win_ptr);
	  raycasting(mlx);
    }
    if (keycode == 100) { // D key to rotate right
         double oldDirX = mlx->dirX;
      mlx->dirX = mlx->dirX * cos(-rotSpeed) - mlx->dirY * sin(-rotSpeed);
      mlx->dirY = oldDirX * sin(-rotSpeed) + mlx->dirY * cos(-rotSpeed);
      double oldPlaneX = mlx->planeX;
      mlx->planeX = mlx->planeX * cos(-rotSpeed) - mlx->planeY * sin(-rotSpeed);
      mlx->planeY = oldPlaneX * sin(-rotSpeed) + mlx->planeY * cos(-rotSpeed);
	   mlx_clear_window(mlx->mlx_p, mlx->win_ptr);
	  raycasting(mlx);
    }
    return 0;
}



int	main(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));

	mlx->mlx_p = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_p, screenWidth, screenHeight, "Raycaster");
	
 mlx_key_hook(mlx->win_ptr, key_hook, mlx); // Hook for key events
	mlx->posX = 22;
	mlx->posY = 12;  //x and y start position
	mlx->dirX = -1;
	mlx->dirY = 0; //initial direction vector
	mlx->planeX = 0;
	mlx->planeY = 0.66; //the 2d raycaster version of camera plane

  mlx->time = 0; //time of current frame
  mlx->oldTime = 0; //time of previous frame

raycasting(mlx);
  	mlx_loop(mlx->mlx_p);
}



// void my_mlx_pixel_put(t_game *mlx, int x, int y, int color) // put the pixel
// {
// 	if (x < 0) // check the x position
// 		return ;
// 	else if (x >= S_W)
// 		return ;
// 	if (y < 0) // check the y position
// 		return ;
// 	else if (y >= S_H)
// 		return ;
// 	mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, color); // put the pixel
// }

// float nor_angle(float angle) // normalize the angle
// {
// 	if (angle < 0)
// 		angle += (2 * M_PI);
// 	if (angle > (2 * M_PI))
// 		angle -= (2 * M_PI);
// 	return (angle);
// }

// void draw_floor_ceiling(t_game *mlx, int ray, int t_pix, int b_pix) // draw the floor and the ceiling
// {
//  int  i;

// 	i = b_pix;
// 	while (i < S_H)
// 		my_mlx_pixel_put(mlx, ray, i++, 0xB99470FF); // floor
// 	i = 0;
// 	while (i < t_pix)
// 		my_mlx_pixel_put(mlx, ray, i++, 0x89CFF3FF); // ceiling
// }

// int get_color(t_game *mlx, int flag) // get the color of the wall
// {
// 	mlx->ray->ray_ngl = nor_angle(mlx->ray->ray_ngl); // normalize the angle
// 	if (flag == 0)
// 	{
// 		if (mlx->ray->ray_ngl > M_PI / 2 && mlx->ray->ray_ngl < 3 * (M_PI / 2))
// 			return (0xB5B5B5FF); // west wall
// 		else
// 			return (0xB5B5B5FF); // east wall
// 	}
// 	else
// 	{
// 		if (mlx->ray->ray_ngl > 0 && mlx->ray->ray_ngl < M_PI)
// 			return (0xF5F5F5FF); // south wall
// 		else
// 			return (0xF5F5F5FF); // north wall
// 	}
// }

// void draw_wall(t_game *mlx, int ray, int t_pix, int b_pix) // draw the wall
// {
// 	int color;

// 	color = get_color(mlx, mlx->ray->flag);
// 	while (t_pix < b_pix)
// 		my_mlx_pixel_put(mlx, ray, t_pix++, color);
// }

// void render_wall(t_game *mlx, int ray) // render the wall
// {
// 	double wall_h;
// 	double b_pix;
// 	double t_pix;

// 	mlx->ray->distance *= cos(nor_angle(mlx->ray->ray_ngl - mlx->ply->angle)); // fix the fisheye
// 	wall_h = (TILE_SIZE / mlx->ray->distance) * ((S_W / 2) / tan(mlx->ply->fov_rd / 2)); // get the wall height
// 	b_pix = (S_H / 2) + (wall_h / 2); // get the bottom pixel
// 	t_pix = (S_H / 2) - (wall_h / 2); // get the top pixel
// 	if (b_pix > S_H) // check the bottom pixel
// 		b_pix = S_H;
// 	if (t_pix < 0) // check the top pixel
// 		t_pix = 0;
// 	draw_wall(mlx, ray, t_pix, b_pix); // draw the wall
// 	draw_floor_ceiling(mlx, ray, t_pix, b_pix); // draw the floor and the ceiling
// }

// int unit_circle(float angle, char c) // check the unit circle
// {
// 	if (c == 'x')
// 	{
// 		if (angle > 0 && angle < M_PI)
// 		return (1);
// 	}
// 	else if (c == 'y')
// 	{
// 		if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
// 		return (1);
// 	}
// 	return (0);
// }

// int inter_check(float angle, float *inter, float *step, int is_horizon) // check the intersection
// {
// 	if (is_horizon)
// 	{
// 		if (angle > 0 && angle < M_PI)
// 		{
// 			*inter += TILE_SIZE;
// 			return (-1);
// 		}
// 		*step *= -1;
// 	}
// 	else
// 	{
// 		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2)) 
// 		{
// 			*inter += TILE_SIZE;
// 			return (-1);
// 		}
// 		*step *= -1;
// 	}
// 	return (1);
// }

// int wall_hit(float x, float y, t_game *mlx) // check the wall hit
// {
// 	int  x_m;
// 	int  y_m;

// 	if (x < 0 || y < 0)
// 		return (0);
// 	x_m = floor(x / TILE_SIZE); // get the x position in the map
// 	y_m = floor(y / TILE_SIZE); // get the y position in the map
// 	if ((y_m >= mlx->dt->h_map || x_m >= mlx->dt->w_map))
// 		return (0);
// 	if (mlx->dt->map2d[y_m] && x_m <= (int)strlen(mlx->dt->map2d[y_m]))
// 		if (mlx->dt->map2d[y_m][x_m] == '1')
// 			return (0);
// 	return (1);
// }

// float get_h_inter(t_game *mlx, float angl) // get the horizontal intersection
// {
// 	float h_x;
// 	float h_y;
// 	float x_step;
// 	float y_step;
// 	int  pixel;

// 	y_step = TILE_SIZE;
// 	x_step = TILE_SIZE / tan(angl);
// 	h_y = floor(mlx->ply->plyr_y / TILE_SIZE) * TILE_SIZE;
// 	pixel = inter_check(angl, &h_y, &y_step, 1);
// 	h_x = mlx->ply->plyr_x + (h_y - mlx->ply->plyr_y) / tan(angl);
// 	if ((unit_circle(angl, 'y') && x_step > 0) || (!unit_circle(angl, 'y') && x_step < 0)) // check x_step value
// 		x_step *= -1;
// 	while (wall_hit(h_x, h_y - pixel, mlx)) // check the wall hit whit the pixel value
// 	{
// 		h_x += x_step;
// 		h_y += y_step;
// 	}
// 	return (sqrt(pow(h_x - mlx->ply->plyr_x, 2) + pow(h_y - mlx->ply->plyr_y, 2))); // get the distance
// }

// float get_v_inter(t_game *mlx, float angl) // get the vertical intersection
// {
// 	float v_x;
// 	float v_y;
// 	float x_step;
// 	float y_step;
// 	int  pixel;

// 	x_step = TILE_SIZE; 
// 	y_step = TILE_SIZE * tan(angl);
// 	v_x = floor(mlx->ply->plyr_x / TILE_SIZE) * TILE_SIZE;
// 	pixel = inter_check(angl, &v_x, &x_step, 0); // check the intersection and get the pixel value
// 	v_y = mlx->ply->plyr_y + (v_x - mlx->ply->plyr_x) * tan(angl);
// 	if ((unit_circle(angl, 'x') && y_step < 0) || (!unit_circle(angl, 'x') && y_step > 0)) // check y_step value
// 		y_step *= -1;
// 	while (wall_hit(v_x - pixel, v_y, mlx)) // check the wall hit whit the pixel value
// 	{
// 		v_x += x_step;
// 		v_y += y_step;
// 	}
// 	return (sqrt(pow(v_x - mlx->ply->plyr_x, 2) + pow(v_y - mlx->ply->plyr_y, 2))); // get the distance
// }

// void cast_rays(t_game *mlx) // cast the rays
// {
// 	double h_inter;
// 	double v_inter;
// 	int  ray;

// 	ray = 0;
// 	mlx->ray->ray_ngl = mlx->ply->angle - (mlx->ply->fov_rd / 2); // the start angle
// 	while (ray < S_W) // loop for the rays
// 	{
// 		mlx->ray->flag = 0; // flag for the wall
// 		h_inter = get_h_inter(mlx, nor_angle(mlx->ray->ray_ngl)); // get the horizontal intersection
// 		v_inter = get_v_inter(mlx, nor_angle(mlx->ray->ray_ngl)); // get the vertical intersection
// 		if (v_inter <= h_inter) // check the distance
// 			mlx->ray->distance = v_inter; // get the distance
// 		else
// 		{
// 			mlx->ray->distance = h_inter; // get the distance
// 			mlx->ray->flag = 1; // flag for the wall
// 		}
// 		render_wall(mlx, ray); // render the wall
// 		ray++; // next ray
// 		mlx->ray->ray_ngl += (mlx->ply->fov_rd / S_W); // next angle
// 	}
// }

// t_data *init_argumet()
// {
// 	t_data *dt = calloc(1, sizeof(t_data));
// 	dt->map2d = calloc(10, sizeof(char *));
// 	dt->map2d[0] = strdup("1111111111111111111111111");
// 	dt->map2d[1] = strdup("1000000000000000000100001");
// 	dt->map2d[2] = strdup("1001000000000P00000000001");
// 	dt->map2d[3] = strdup("1001000000000000001000001");
// 	dt->map2d[4] = strdup("1001000000000000001000001");
// 	dt->map2d[5] = strdup("1001000000100000001000001");
// 	dt->map2d[6] = strdup("1001000000000000001000001");
// 	dt->map2d[7] = strdup("1001000000001000001000001");
// 	dt->map2d[8] = strdup("1111111111111111111111111");
// 	dt->map2d[9] = NULL;
// 	dt->p_y = 3;
// 	dt->p_x = 14;
// 	dt->w_map = 25;
// 	dt->h_map = 9;
// 	return (dt);
// }

// void init_the_player(t_game *game)
// {
// 	game->ply->plyr_x = game->dt->p_x * TILE_SIZE + TILE_SIZE / 2;
// 	game->ply->plyr_y = game->dt->p_y * TILE_SIZE + TILE_SIZE / 2;
// 	game->ply->fov_rd = (FOV * M_PI) / 180;
// 	game->ply->angle = M_PI;
// }

// // int game_loop(t_game *ml) // game loop
// // {
// // 	// t_game *mlx;

// // 	// mlx = ml; // cast to the mlx structure
// // 	// mlx_delete_image(mlx->mlx_p, mlx->img); // delete the image
// // 	// mlx->img = mlx_new_image(mlx->mlx_p, S_W, S_H); // create new image
// // 	// hook(mlx, 0, 0); // hook the player
// // 	cast_rays(ml); // cast the rays
// // 	// mlx_image_to_window(mlx->mlx_p, mlx->img, 0, 0); // put the image to the window
// // 	return 0;
// // }

// void start_the_game(t_data *data) // start the game
// {
// 	t_game	*game;

// 	game = malloc(sizeof(t_game));

// 	game->dt = data;
// 	game->ply = calloc(1, sizeof(t_player));
// 	game->ray = calloc(1, sizeof(t_ray));
// 	game->mlx_ptr = mlx_init();
// 	game->win_ptr = mlx_new_window(game->mlx_ptr, 320, 240, "cub3d");
// 	init_the_player(game);
// 	cast_rays(game);
// 	mlx_loop(game->mlx_ptr);

// 	// t_mlx mlx;
// // 
// 	// mlx.dt = dt; // init the mlx structure
// 	// mlx.ply = calloc(1, sizeof(t_player)); // init the player structure i'm using calloc to initialize the variables to zero
// 	// mlx.ray = calloc(1, sizeof(t_ray)); // init the ray structure
// 	// mlx.mlx_p = mlx_init(S_W, S_H, "Cub3D", 0); // init the mlx pointer and put a window to the screen
// 	// init_the_player(mlx); // init the player structure
// 	// mlx_loop_hook(game->mlx_ptr, &game_loop, &game); // game loop continuously call a specified function to update the game state and render the frames.
// 	// mlx_key_hook(mlx.mlx_p, &mlx_key, &mlx); // key press and release
// 	// mlx_loop(mlx.mlx_p); // mlx loop
// 	// ft_exit(&mlx); // exit the game
// }

// int	main(void)
// {
// 	t_data	*data;

// 	data = init_argumet();
// 	start_the_game(data);
// }



// void my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color) // put the pixel
// {
// 	if (x < 0) // check the x position
// 		return ;
// 	else if (x >= S_W)
// 		return ;
// 	if (y < 0) // check the y position
// 		return ;
// 	else if (y >= S_H)
// 		return ;
// 	mlx_pixel_put(mlx->mlx_p, mlx->win_ptr, x, y, color); // put the pixel
// }

// float nor_angle(float angle) // normalize the angle
// {
// 	if (angle < 0)
// 		angle += (2 * M_PI);
// 	if (angle > (2 * M_PI))
// 		angle -= (2 * M_PI);
// 	return (angle);
// }

// void draw_floor_ceiling(t_mlx *mlx, int ray, int t_pix, int b_pix) // draw the floor and the ceiling
// {
//  int  i;
// //  int  c;

// 	i = b_pix;
// 	while (i < S_H)
// 		my_mlx_pixel_put(mlx, ray, i++, 0xB99470FF); // floor
// 	i = 0;
// 	while (i < t_pix)
// 		my_mlx_pixel_put(mlx, ray, i++, 0x89CFF3FF); // ceiling
// }

// int get_color(t_mlx *mlx, int flag) // get the color of the wall
// {
// 	mlx->ray->ray_ngl = nor_angle(mlx->ray->ray_ngl); // normalize the angle
// 	if (flag == 0)
// 	{
// 		if (mlx->ray->ray_ngl > M_PI / 2 && mlx->ray->ray_ngl < 3 * (M_PI / 2))
// 			return (0xB5B5B5FF); // west wall
// 		else
// 			return (0xB5B5B5FF); // east wall
// 	}
// 	else
// 	{
// 		if (mlx->ray->ray_ngl > 0 && mlx->ray->ray_ngl < M_PI)
// 			return (0xF5F5F5FF); // south wall
// 		else
// 			return (0xF5F5F5FF); // north wall
// 	}
// }

// void draw_wall(t_mlx *mlx, int ray, int t_pix, int b_pix) // draw the wall
// {
// 	int color;

// 	color = get_color(mlx, mlx->ray->flag);
// 	while (t_pix < b_pix)
// 		my_mlx_pixel_put(mlx, ray, t_pix++, color);
// }

// void render_wall(t_mlx *mlx, int ray) // render the wall
// {
// 	double wall_h;
// 	double b_pix;
// 	double t_pix;

// 	mlx->ray->distance *= cos(nor_angle(mlx->ray->ray_ngl - mlx->ply->angle)); // fix the fisheye
// 	wall_h = (TILE_SIZE / mlx->ray->distance) * ((S_W / 2) / tan(mlx->ply->fov_rd / 2)); // get the wall height
// 	b_pix = (S_H / 2) + (wall_h / 2); // get the bottom pixel
// 	t_pix = (S_H / 2) - (wall_h / 2); // get the top pixel
// 	if (b_pix > S_H) // check the bottom pixel
// 		b_pix = S_H;
// 	if (t_pix < 0) // check the top pixel
// 		t_pix = 0;
// 	draw_wall(mlx, ray, t_pix, b_pix); // draw the wall
// 	draw_floor_ceiling(mlx, ray, t_pix, b_pix); // draw the floor and the ceiling
// }








// int unit_circle(float angle, char c) // check the unit circle
// {
// 	if (c == 'x')
// 	{
// 		if (angle > 0 && angle < M_PI)
// 		return (1);
// 	}
// 	else if (c == 'y')
// 	{
// 		if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
// 		return (1);
// 	}
// 	return (0);
// }

// int inter_check(float angle, float *inter, float *step, int is_horizon) // check the intersection
// {
// 	if (is_horizon)
// 	{
// 		if (angle > 0 && angle < M_PI)
// 		{
// 			*inter += TILE_SIZE;
// 			return (-1);
// 		}
// 		*step *= -1;
// 	}
// 	else
// 	{
// 		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2)) 
// 		{
// 			*inter += TILE_SIZE;
// 			return (-1);
// 		}
// 		*step *= -1;
// 	}
// 	return (1);
// }

// int wall_hit(float x, float y, t_mlx *mlx) // check the wall hit
// {
// 	int  x_m;
// 	int  y_m;

// 	if (x < 0 || y < 0)
// 		return (0);
// 	x_m = floor (x / TILE_SIZE); // get the x position in the map
// 	y_m = floor (y / TILE_SIZE); // get the y position in the map
// 	if ((y_m >= mlx->dt->h_map || x_m >= mlx->dt->w_map))
// 		return (0);
// 	if (mlx->dt->map2d[y_m] && x_m <= (int)strlen(mlx->dt->map2d[y_m]))
// 		if (mlx->dt->map2d[y_m][x_m] == '1')
// 			return (0);
// 	return (1);
// }

// float get_h_inter(t_mlx *mlx, float angl) // get the horizontal intersection
// {
// 	float h_x;
// 	float h_y;
// 	float x_step;
// 	float y_step;
// 	int  pixel;

// 	y_step = TILE_SIZE;
// 	x_step = TILE_SIZE / tan(angl);
// 	h_y = floor(mlx->ply->plyr_y / TILE_SIZE) * TILE_SIZE;
// 	pixel = inter_check(angl, &h_y, &y_step, 1);
// 	h_x = mlx->ply->plyr_x + (h_y - mlx->ply->plyr_y) / tan(angl);
// 	if ((unit_circle(angl, 'y') && x_step > 0) || (!unit_circle(angl, 'y') && x_step < 0)) // check x_step value
// 		x_step *= -1;
// 	while (wall_hit(h_x, h_y - pixel, mlx)) // check the wall hit whit the pixel value
// 	{
// 		h_x += x_step;
// 		h_y += y_step;
// 	}
// 	return (sqrt(pow(h_x - mlx->ply->plyr_x, 2) + pow(h_y - mlx->ply->plyr_y, 2))); // get the distance
// }

// float get_v_inter(t_mlx *mlx, float angl) // get the vertical intersection
// {
// 	float v_x;
// 	float v_y;
// 	float x_step;
// 	float y_step;
// 	int  pixel;

// 	x_step = TILE_SIZE; 
// 	y_step = TILE_SIZE * tan(angl);
// 	v_x = floor(mlx->ply->plyr_x / TILE_SIZE) * TILE_SIZE;
// 	pixel = inter_check(angl, &v_x, &x_step, 0); // check the intersection and get the pixel value
// 	v_y = mlx->ply->plyr_y + (v_x - mlx->ply->plyr_x) * tan(angl);
// 	if ((unit_circle(angl, 'x') && y_step < 0) || (!unit_circle(angl, 'x') && y_step > 0)) // check y_step value
// 		y_step *= -1;
// 	while (wall_hit(v_x - pixel, v_y, mlx)) // check the wall hit whit the pixel value
// 	{
// 		v_x += x_step;
// 		v_y += y_step;
// 	}
// 	return (sqrt(pow(v_x - mlx->ply->plyr_x, 2) + pow(v_y - mlx->ply->plyr_y, 2))); // get the distance
// }

// void cast_rays(t_mlx *mlx) // cast the rays
// {
// 	double h_inter;
// 	double v_inter;
// 	int  ray;

// 	ray = 0;
// 	mlx->ray->ray_ngl = mlx->ply->angle - (mlx->ply->fov_rd / 2); // the start angle
// 	while (ray < S_W) // loop for the rays
// 	{
// 		mlx->ray->flag = 0; // flag for the wall
// 		h_inter = get_h_inter(mlx, nor_angle(mlx->ray->ray_ngl)); // get the horizontal intersection
// 		v_inter = get_v_inter(mlx, nor_angle(mlx->ray->ray_ngl)); // get the vertical intersection
// 		if (v_inter <= h_inter) // check the distance
// 			mlx->ray->distance = v_inter; // get the distance
// 		else
// 		{
// 			mlx->ray->distance = h_inter; // get the distance
// 			mlx->ray->flag = 1; // flag for the wall
// 		}
// 		render_wall(mlx, ray); // render the wall
// 		ray++; // next ray
// 		mlx->ray->ray_ngl += (mlx->ply->fov_rd / S_W); // next angle
// 	}
// }





// void mlx_key(int keydata, void *ml)	// key press
// {
// 	t_mlx	*mlx;

// 	mlx = ml;
// 	if (keydata == 115 ) // move left
// 		mlx->ply->l_r = -1;
// 	else if (keydata == 97 ) // move right
// 		mlx->ply->l_r = 1;
// }

// void	rotate_player(t_mlx *mlx, int i)	// rotate the player
// {
// 	if (i == 1)
// 	{
// 		mlx->ply->angle += ROTATION_SPEED; // rotate right
// 		if (mlx->ply->angle > 2 * M_PI)
// 			mlx->ply->angle -= 2 * M_PI;
// 	}
// 	else
// 	{
// 		mlx->ply->angle -= ROTATION_SPEED; // rotate left
// 		if (mlx->ply->angle < 0)
// 			mlx->ply->angle += 2 * M_PI;
// 	}
// }

// void	move_player(t_mlx *mlx, double move_x, double move_y)	// move the player
// {
// 	int		map_grid_y;
// 	int		map_grid_x;
// 	int		new_x;
// 	int		new_y;

// 	new_x = roundf(mlx->ply->plyr_x + move_x); // get the new x position
// 	new_y = roundf(mlx->ply->plyr_y + move_y); // get the new y position
// 	map_grid_x = (new_x / TILE_SIZE); // get the x position in the map
// 	map_grid_y = (new_y / TILE_SIZE); // get the y position in the map
// 	if (mlx->dt->map2d[map_grid_y][map_grid_x] != '1' && \
// 	(mlx->dt->map2d[map_grid_y][mlx->ply->plyr_x / TILE_SIZE] != '1' && \
// 	mlx->dt->map2d[mlx->ply->plyr_y / TILE_SIZE][map_grid_x] != '1')) // check the wall hit and the diagonal wall hit
// 	{
// 		mlx->ply->plyr_x = new_x; // move the player
// 		mlx->ply->plyr_y = new_y; // move the player
// 	}
// }

// void	hook(t_mlx *mlx, double move_x, double move_y)	// hook the player
// {
// 	if (mlx->ply->rot == 1) //rotate right
// 		rotate_player(mlx, 1);
// 	if (mlx->ply->rot == -1) //rotate left
// 		rotate_player(mlx, 0);
// 	if (mlx->ply->l_r == 1) //move right
// 	{
// 		move_x = -sin(mlx->ply->angle) * PLAYER_SPEED;
// 		move_y = cos(mlx->ply->angle) * PLAYER_SPEED;
// 	}
// 	if (mlx->ply->l_r == -1) //move left
// 	{
// 		move_x = sin(mlx->ply->angle) * PLAYER_SPEED;
// 		move_y = -cos(mlx->ply->angle) * PLAYER_SPEED;
// 	}
// 	if (mlx->ply->u_d == 1) //move up
// 	{
// 		move_x = cos(mlx->ply->angle) * PLAYER_SPEED;
// 		move_y = sin(mlx->ply->angle) * PLAYER_SPEED;
// 	}
// 	if (mlx->ply->u_d == -1) //move down
// 	{
// 		move_x = -cos(mlx->ply->angle) * PLAYER_SPEED;
// 		move_y = -sin(mlx->ply->angle) * PLAYER_SPEED;
// 	}
// 	move_player(mlx, move_x, move_y); // move the player
// }











// int game_loop(void *ml) // game loop
// {
// 	t_mlx *mlx;

// 	mlx = ml; // cast to the mlx structure
// 	mlx_destroy_image(mlx->mlx_p, mlx->img); // delete the image
// 	mlx->img = mlx_new_image(mlx->mlx_p, S_W, S_H); // create new image
// 	// hook(mlx, 0, 0); // hook the player
// 	cast_rays(mlx); // cast the rays
// 	mlx_put_image_to_window(mlx->mlx_p,mlx->win_ptr, mlx->img, 0, 0); // put the image to the window
// 	return (0);
// }

// void init_the_player(t_mlx mlx) // init the player structure
// {
// 	mlx.ply->plyr_x = mlx.dt->p_x * TILE_SIZE + TILE_SIZE / 2; // player x position in pixels in the center of the tile
// 	mlx.ply->plyr_y = mlx.dt->p_y * TILE_SIZE + TILE_SIZE / 2; // player y position in pixels in the center of the tile
// 	mlx.ply->fov_rd = (FOV * M_PI) / 180; // field of view in radians
// 	mlx.ply->angle = M_PI; // player angle
// 	//the rest of the variables are initialized to zero by calloc
// }

// void start_the_game(t_data *dt) // start the game
// {
// 	t_mlx mlx;

// 	mlx.dt = dt; // init the mlx structure
// 	mlx.ply = calloc(1, sizeof(t_player)); // init the player structure i'm using calloc to initialize the variables to zero
// 	mlx.ray = calloc(1, sizeof(t_ray)); // init the ray structure
// 	mlx.mlx_p = mlx_init(); // init the mlx pointer and put a window to the screen
// 	mlx.win_ptr = mlx_new_window(mlx.mlx_p, 320, 240, "cub3d");
// 	mlx.img = mlx_new_image(mlx.mlx_p, S_W, S_H);
// 	init_the_player(mlx); // init the player structure
// 	mlx_loop_hook(mlx.mlx_p, &game_loop, &mlx); // game loop continuously call a specified function to update the game state and render the frames.
// 	// mlx_key_hook(mlx.mlx_p, &mlx_key, &mlx); // key press and release
// 	mlx_loop(mlx.mlx_p); // mlx loop
// 	// ft_exit(&mlx); // exit the game
// }

// //################################################################################################//
// //############################## THE MAIN FUNCTION AND INIT THE MAP ##############################//
// //################################################################################################//

// t_data *init_argumet() // init the data structure
// {
// 	t_data *dt = calloc(1, sizeof(t_data)); // init the data structure
// 	dt->map2d = calloc(10, sizeof(char *)); // init the map
// 	dt->map2d[0] = strdup("1111111111111111111111111"); //fill the map
// 	dt->map2d[1] = strdup("1000000000000000000100001");
// 	dt->map2d[2] = strdup("1001000000000P00000000001");
// 	dt->map2d[3] = strdup("1001000000000000001000001");
// 	dt->map2d[4] = strdup("1001000000000000001000001");
// 	dt->map2d[5] = strdup("1001000000100000001000001");
// 	dt->map2d[6] = strdup("1001000000000000001000001");
// 	dt->map2d[7] = strdup("1001000000001000001000001");
// 	dt->map2d[8] = strdup("1111111111111111111111111");
// 	dt->map2d[9] = NULL;
// 	dt->p_y = 3; // player y position in the map
// 	dt->p_x = 14; // player x position in the map
// 	dt->w_map = 25; // map width
// 	dt->h_map = 9; // map height
// 	return (dt); // return the data structure
// }

// int main() // main function
// {
//  t_data *data;

// 	data = init_argumet(); // init the data structure
// 	start_the_game(data); // start the game
// 	return 0;
// }

// --------------------------------------------------------




// --------------------------------------------------------


// int main(int /*argc*/, char */*argv*/[])
// {
//   double posX = 22, posY = 12;  //x and y start position
//   double dirX = -1, dirY = 0; //initial direction vector
//   double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

//   double time = 0; //time of current frame
//   double oldTime = 0; //time of previous frame

//   screen(screenWidth, screenHeight, 0, "Raycaster");
//   while(!done())
//   {
//     for(int x = 0; x < w; x++)
//     {
//       //calculate ray position and direction
//       double cameraX = 2 * x / (double)w - 1; //x-coordinate in camera space
//       double rayDirX = dirX + planeX * cameraX;
//       double rayDirY = dirY + planeY * cameraX;
//       //which box of the map we're in
//       int mapX = int(posX);
//       int mapY = int(posY);

//       //length of ray from current position to next x or y-side
//       double sideDistX;
//       double sideDistY;

//       //length of ray from one x or y-side to next x or y-side
//       //these are derived as:
//       //deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX))
//       //deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY))
//       //which can be simplified to abs(|rayDir| / rayDirX) and abs(|rayDir| / rayDirY)
//       //where |rayDir| is the length of the vector (rayDirX, rayDirY). Its length,
//       //unlike (dirX, dirY) is not 1, however this does not matter, only the
//       //ratio between deltaDistX and deltaDistY matters, due to the way the DDA
//       //stepping further below works. So the values can be computed as below.
//       // Division through zero is prevented, even though technically that's not
//       // needed in C++ with IEEE 754 floating point values.
//       double deltaDistX = (rayDirX == 0) ? 1e30 : std::abs(1 / rayDirX);
//       double deltaDistY = (rayDirY == 0) ? 1e30 : std::abs(1 / rayDirY);

//       double perpWallDist;

//       //what direction to step in x or y-direction (either +1 or -1)
//       int stepX;
//       int stepY;

//       int hit = 0; //was there a wall hit?
//       int side; //was a NS or a EW wall hit?
//       //calculate step and initial sideDist
//       if(rayDirX < 0)
//       {
//         stepX = -1;
//         sideDistX = (posX - mapX) * deltaDistX;
//       }
//       else
//       {
//         stepX = 1;
//         sideDistX = (mapX + 1.0 - posX) * deltaDistX;
//       }
//       if(rayDirY < 0)
//       {
//         stepY = -1;
//         sideDistY = (posY - mapY) * deltaDistY;
//       }
//       else
//       {
//         stepY = 1;
//         sideDistY = (mapY + 1.0 - posY) * deltaDistY;
//       }
//       //perform DDA
//       while(hit == 0)
//       {
//         //jump to next map square, either in x-direction, or in y-direction
//         if(sideDistX < sideDistY)
//         {
//           sideDistX += deltaDistX;
//           mapX += stepX;
//           side = 0;
//         }
//         else
//         {
//           sideDistY += deltaDistY;
//           mapY += stepY;
//           side = 1;
//         }
//         //Check if ray has hit a wall
//         if(worldMap[mapX][mapY] > 0) hit = 1;
//       }
//       //Calculate distance projected on camera direction. This is the shortest distance from the point where the wall is
//       //hit to the camera plane. Euclidean to center camera point would give fisheye effect!
//       //This can be computed as (mapX - posX + (1 - stepX) / 2) / rayDirX for side == 0, or same formula with Y
//       //for size == 1, but can be simplified to the code below thanks to how sideDist and deltaDist are computed:
//       //because they were left scaled to |rayDir|. sideDist is the entire length of the ray above after the multiple
//       //steps, but we subtract deltaDist once because one step more into the wall was taken above.
//       if(side == 0) perpWallDist = (sideDistX - deltaDistX);
//       else          perpWallDist = (sideDistY - deltaDistY);

//       //Calculate height of line to draw on screen
//       int lineHeight = (int)(h / perpWallDist);

//       //calculate lowest and highest pixel to fill in current stripe
//       int drawStart = -lineHeight / 2 + h / 2;
//       if(drawStart < 0) drawStart = 0;
//       int drawEnd = lineHeight / 2 + h / 2;
//       if(drawEnd >= h) drawEnd = h - 1;

//       //choose wall color
//       ColorRGB color;
//       switch(worldMap[mapX][mapY])
//       {
//         case 1:  color = RGB_Red;    break; //red
//         case 2:  color = RGB_Green;  break; //green
//         case 3:  color = RGB_Blue;   break; //blue
//         case 4:  color = RGB_White;  break; //white
//         default: color = RGB_Yellow; break; //yellow
//       }

//       //give x and y sides different brightness
//       if(side == 1) {color = color / 2;}

//       //draw the pixels of the stripe as a vertical line
//       verLine(x, drawStart, drawEnd, color);
//     }
//     //timing for input and FPS counter
//     oldTime = time;
//     time = getTicks();
//     double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
//     print(1.0 / frameTime); //FPS counter
//     redraw();
//     cls();

//     //speed modifiers
//     double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
//     double rotSpeed = frameTime * 3.0; //the constant value is in radians/second
//     readKeys();
//     //move forward if no wall in front of you
//     if(keyDown(SDLK_UP))
//     {
//       if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
//       if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
//     }
//     //move backwards if no wall behind you
//     if(keyDown(SDLK_DOWN))
//     {
//       if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
//       if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
//     }
//     //rotate to the right
//     if(keyDown(SDLK_RIGHT))
//     {
//       //both camera direction and camera plane must be rotated
//       double oldDirX = dirX;
//       dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
//       dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
//       double oldPlaneX = planeX;
//       planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
//       planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
//     }
//     //rotate to the left
//     if(keyDown(SDLK_LEFT))
//     {
//       //both camera direction and camera plane must be rotated
//       double oldDirX = dirX;
//       dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
//       dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
//       double oldPlaneX = planeX;
//       planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
//       planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
//     }
//   }
// }