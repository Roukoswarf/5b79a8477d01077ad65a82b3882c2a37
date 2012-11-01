/*
Created by Alexander Diana (Student Number: 100458717)
		   Jeff Carey      (Student Number: 100451635)
*/

// place image at position on screen
void put(int x, int y, SDL_Surface* image, SDL_Surface* screen)
{
    //Temporary rectangle to hold the offsets
    SDL_Rect offset;
    
    //Get the offsets
    offset.x = x;
    offset.y = y;
    
    //add to surface
    SDL_BlitSurface(image, NULL, screen, &offset);
}

// place image at position with rotation of [angle] on screen
void put(int x, int y, double angle, SDL_Surface* image, SDL_Surface* screen) {
	//Temporary rectangle to hold the offsets
    SDL_Rect offset;
    
    //Get the offsets
    offset.x = x;
    offset.y = y;

	// rotate to angle
	image = rotozoomSurface(image, angle, 1, 1);
    
    //add to surface
    SDL_BlitSurface(image, NULL, screen, &offset);
}

// place image on screen with angle and zoom
void put(int x, int y, double angle, double zoom, SDL_Surface* image, SDL_Surface* screen) {
	//Temporary rectangle to hold the offsets
    SDL_Rect offset;
    
    //Get the offsets
    offset.x = x;
    offset.y = y;

	// rotate to angle
	image = rotozoomSurface(image, angle, zoom, 1);
    
    //add to surface
    SDL_BlitSurface(image, NULL, screen, &offset);
}

// place image on screen cropped from a section of larger image
void put( int x, int y, int areaw, int areah, SDL_Surface* image, SDL_Surface* screen)
{
    //Temporary rectangle to hold the offsets
    SDL_Rect offset;
    
    //Get the offsets
    offset.x = x;
    offset.y = y;

	offset.w = areaw;
	offset.h = areah;
    
    //add to surface
    SDL_BlitSurface(image, NULL, screen, &offset);
}

//Test to see if the points x and y are contained in the given rectangle.
bool isin (int x, int y, SDL_Rect* rect)
{
	if (rect->x <= x && rect->x + rect->w >= x && rect->y <= y && rect->y + rect->h >= y)
		return true;
	return false;
}

//Test to see if the points x and y are contained in the given rectangle.
bool isin (int x, int y, int rectx, int recty, int rectw, int recth)
{
	if (rectx <= x && rectx + rectw >= x && recty <= y && recty + recth >= y)
		return true;
	return false;
}