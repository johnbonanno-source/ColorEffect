#include "bitmap.h"
#include "coloreffect.h"
#include <stdio.h>
#include <stdlib.h>


 void blow_up(const char *input_image, const char *output_image){

		struct bitmap color;
	     	color =load_bitmap_from_file(input_image);//open pointer to bitmap colorful.png
		struct bitmap* fptr;
	       	fptr = &color;

	
	int height = fptr ->height;
	int width = fptr->width;
	
	int hGrow = height*2;
	int wGrow = width*2;


	struct bitmap enlarge;//needs ptr
	enlarge =new_bitmap(wGrow,height );
	
	struct bitmap* huge = &enlarge;
	
	struct bitmap h ;//needs ptr
	h =new_bitmap(wGrow,hGrow);
	struct bitmap* hugeFinal = &h;
	
	pixel* blowup;
	
	pixel* current;

	int r = 0;
	int g = 0;
	int b = 0;


	for (int y = 0;y<(height);y++){

		for (int x = 0; x<(width);x++){
	//	2x,2y, 2x+1,2y+1	
			
			current = get_pixel(fptr,x,y);
			r=get_red(current);
			g=get_green(current);
			b=get_blue(current);  



		//	set_color(blowup,r,g,b);
		//	blowup = get_pixel(huge,x,2*y+1);
		//	set_color(blowup, r, g, b);
			blowup = get_pixel(huge,2*x+1,y);
			set_color(blowup, r, g, b);	
			
		
			blowup = get_pixel(huge,2*x,y);
			set_color(blowup, r, g, b);
	
		//blowup = get_pixel(huge,x,2*y);
	
		///	set_color(blowup, r, g, b);	

		
	

				}
	}

	
 	for (int y = 0;y<(height);y++){

		for (int x = 0; x<(width*2);x++){
	//	2x,2y, 2x+1,2y+1	
			
			current = get_pixel(huge,x,y);
			r=get_red(current);
			g=get_green(current);
			b=get_blue(current);  



		//	set_color(blowup,r,g,b);
			blowup = get_pixel(hugeFinal,x,2*y+1);
			set_color(blowup, r, g, b);
		//	blowup = get_pixel(huge,2*x+1,y);
		//	set_color(blowup, r, g, b);	
			
		
		//	blowup = get_pixel(huge,2*x,y);
		//	set_color(blowup, r, g, b);
	
			blowup = get_pixel(hugeFinal,x,2*y);
	//
			set_color(blowup, r, g, b);	

	

				}
	}
	
			save_bitmap_to_file(hugeFinal,output_image);
			
			free_bitmap(hugeFinal);

}


 void posterize(const char *input_image, const char *output_image){


		struct bitmap color;
	//	struct bitmap* oPtr;
	     	color =load_bitmap_from_file(input_image);//open pointer to bitmap colorful.png
		struct bitmap* fptr;
	       	fptr = &color;
	//	struct bitmap load_bitmap_from_file(input_image); 

	
	int height = fptr ->height;
	int width = fptr->width;

	pixel* current;

	

	int r = 0;
	int g = 0;
	int b = 0;

	
	
	

	for (int y = 0; y<height;y++){
		for (int x = 0; x<width;x++){
			current = get_pixel(fptr,x,y);
				r = get_red(current);
				g =get_green(current);
				b =get_blue(current);
		
		if(r<0 && r<63){
			set_color(current,32,g,b);
			r=32;
		}
		else if(r>64 && r<127){
			set_color(current,96,g,b);
			r = 96;}
		else if(r>128 && r<191){
			set_color(current,160,g,b);
			r=160;}
		else if(r>=192){set_color(current,224,g,b);
			r = 224;}
	
	if(g<0 && g<63){
			set_color(current,r,32,b);
			g=32;
		}
		else if(g>64 && g<127){
			set_color(current,r,96,b);
			g = 96;}
		else if(g>128 && g<191){
			set_color(current,r,160,b);
			g=160;}
		else if(g>=192){set_color(current,r,224,b);
			g = 224;}
	if(b<0 && b<63){
			set_color(current,r,g,32);
			b=32;
		}
		else if(b>64 && b<127){
			set_color(current,r,g,96);
			b = 96;}
		else if(b>128 && b<191){
			set_color(current,r,g,160);
			b=160;}
		else if(b>=192){set_color(current,r,g,224);
			b = 224;}
		}
	}

save_bitmap_to_file(fptr,output_image);

		free_bitmap(fptr);
}//end posterize 

void make_grayscale(const char *input_image, const char *output_image){
		struct bitmap color;
	     	color =load_bitmap_from_file(input_image);//open pointer to bitmap colorful.png
		struct bitmap* fptr;
	       	fptr = &color;
		int height =fptr->height;
		int width =fptr->width;
		pixel* current;
		int avgCtr = 0;


		int r;
		int g;
		int b;

		for (int y = 0; y<height;y++){
			for (int x = 0; x<width;x++){
				current = get_pixel(fptr,x,y);
				r = get_red(current);
				g =get_green(current);
				b =get_blue(current);
				avgCtr=(r+g+b)/3;
				set_color(current,avgCtr,avgCtr,avgCtr);
		}
	}
save_bitmap_to_file(fptr,output_image);
free_bitmap(fptr);	
}//end grayscale

int main()
{
blow_up("colorful.png", "huge.png");
make_grayscale("colorful.png", "grayscale.png");
posterize("colorful.png", "cartoon.png");

return 0;
}
