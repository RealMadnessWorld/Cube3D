// #include "cub3d.h"

// void	print_validation(char *str)
// {
// 		if (find_extention(str, ".xpm"))
// 			printf(CLR_GRN"all good 👌\n");
// 		else
// 			printf(CLR_RED"nope 🚫\n");
// }

// void	print_map_shit(t_data *d)
// {
// 	int i = 0;
// 	int x = 0;

// 	printf(CLR_RED"\n			IMAGES AND COLORS\n\n"CLR_RST);

// 	printf(CLR_YLW"NO -> ");
// 	printf(CLR_CYN"\"%d\"  " , d->map.no_img);
// 	printf(CLR_YLW"right extention: "CLR_RST);
// 	print_validation(d->map.no_img);

// 	printf(CLR_YLW"SO -> ");
// 	printf(CLR_CYN"\"%d\"  ", d->map.so_img);
// 	printf(CLR_YLW"right extention: "CLR_RST);
// 	print_validation(d->map.so_img);

// 	printf(CLR_YLW"WE -> ");
// 	printf(CLR_CYN"\"%d\"  ", d->map.we_img);
// 	printf(CLR_YLW"right extention: "CLR_RST);
// 	print_validation(d->map.we_img);

// 	printf(CLR_YLW"EA -> ");
// 	printf(CLR_CYN"\"%d\"  ", d->map.ea_img);
// 	printf(CLR_YLW"right extention: "CLR_RST);
// 	print_validation(d->map.ea_img);

// 	printf(CLR_YLW"F ->  ");
// 	printf(CLR_CYN"\"[%d][%d][%d]\"\n"CLR_RST, d->map.f_color[0], d->map.f_color[1], d->map.f_color[2]);

// 	printf(CLR_YLW"C ->  ");
// 	printf(CLR_CYN"\"[%d][%d][%d]\"\n"CLR_RST, d->map.c_color[0], d->map.c_color[1], d->map.c_color[2]);


// 	printf(CLR_BLU"\n		--------------------------------\n\n"CLR_RST);
// 	printf(CLR_RED"				MAP\n\n"CLR_RST);

// 	printf(CLR_YLW"player starting y position: "CLR_RST);
// 	printf(CLR_CYN"%i\n"CLR_RST, d->map.play_y);
// 	printf(CLR_YLW"player starting x position: "CLR_RST);
// 	printf(CLR_CYN"%i\n\n"CLR_RST, d->map.play_x);

// 	while(d->map.map[i])
// 		printf(CLR_GRN"%s\n"CLR_RST, d->map.map[i++]);

// 	printf("\n\nmap int\n\n");

// 	i = 0;
// 	while(i < d->map.height)
// 	{
// 		x = 0;
// 		printf("{");
// 		while(x < d->map.width)
// 		{
// 			printf("%i", d->mapito[i][x]);
// 			x++;
// 		}
// 		printf("}\n");
// 		i++;
// 	}

// 	printf(CLR_RED"\nDONT FORGET THAT THE PROGRAM DOESNT CHECK FOR EXTENSIONS YET!!!!!\n"CLR_RST);
// 	printf(CLR_GRN"\nYES. is does :3\n"CLR_RST);
// }
