#include "cub3d.h"

void	print_validation(char *str)
{
		if (find_extention(str, ".xpm"))
			printf(CLR_GRN"all good 👌\n");
		else
			printf(CLR_RED"nope 🚫\n");
}

void	print_map_shit(t_data *d)
{
	printf(CLR_RED"\n			IMAGES AND COLORS\n\n"CLR_RST);

	printf(CLR_YLW"NO -> ");
	printf(CLR_CYN"\"%s\"  " , d->map.no_img);
	printf(CLR_YLW"right extention: "CLR_RST);
	print_validation(d->map.no_img);
	
	printf(CLR_YLW"SO -> ");
	printf(CLR_CYN"\"%s\"  ", d->map.so_img);
	printf(CLR_YLW"right extention: "CLR_RST);
	print_validation(d->map.so_img);

	printf(CLR_YLW"WE -> ");
	printf(CLR_CYN"\"%s\"  ", d->map.we_img);
	printf(CLR_YLW"right extention: "CLR_RST);
	print_validation(d->map.we_img);

	printf(CLR_YLW"EA -> ");
	printf(CLR_CYN"\"%s\"  ", d->map.ea_img);
	printf(CLR_YLW"right extention: "CLR_RST);
	print_validation(d->map.ea_img);

	printf(CLR_YLW"F ->  ");
	printf(CLR_CYN"\"%s\"\n"CLR_RST, d->map.f_img);
	
	printf(CLR_YLW"C ->  ");
	printf(CLR_CYN"\"%s\"\n"CLR_RST, d->map.c_img);

	printf(CLR_BLU"\n\n--------------------------------\n"CLR_RST);
	printf(CLR_RED"\n				MAP\n\n"CLR_RST);



}