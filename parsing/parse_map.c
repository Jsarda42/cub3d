#include "cube.h"

void parse_map()
{
    i = init_map_texture(data);
	tmp_i = i;
	while (data->map_data.map_str[i])
	{
		x = 0;
		while (data->map_data.map_str[i][x])
		{
			if (data->map_data.map_str[i][x] == ' ' || data->map_data.map_str[i][x] == '1' || data->map_data.map_str[i][x] == '2' || data->map_data.map_str[i][x] == '0' || data->map_data.map_str[i][x] == 'E' || data->map_data.map_str[i][x] == '\n')
				x++;
			else

				ft_errors(data, "Wrong identifier in map", 1);
		}
		data->line.x = x;
		i++;
	}
	data->line.y = i - tmp_i;
}