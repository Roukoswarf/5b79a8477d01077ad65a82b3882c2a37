/*
Created by Alexander Diana (Student Number: 100458717)
		   Jeff Carey      (Student Number: 100451635)
*/

SDL_Surface* init() {
	// window properties
	const int SCREEN_WIDTH = 850;
	const int SCREEN_HEIGHT = 480;
	const int SCREEN_BPP = 32;

    //Initialize SDL video sybsystem
    SDL_Init(SDL_INIT_EVERYTHING);

	//Set window icon
	SDL_Surface* icon = SDL_LoadBMP("icon.bmp");
	SDL_SetColorKey(icon, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(icon->format, 0, 255, 0));
	SDL_WM_SetIcon(icon, NULL);
    
    //Set up the screen
    SDL_Surface* screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_HWPALETTE );
 
    //Set the window title
    SDL_WM_SetCaption( "Traffic Simulator", NULL );

	

	//Initialize the TTF font renderer
	TTF_Init();
    
    //If everything initialized fine
    return screen;
}