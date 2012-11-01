/*
Created by Alexander Diana (Student Number: 100458717)
		   Jeff Carey      (Student Number: 100451635)
*/

// load image onto surface based on filename
SDL_Surface* load(std::string filename) 
{
    //The image that's loaded
    SDL_Surface* temp = SDL_LoadBMP(filename.c_str());

	SDL_Surface* image = NULL;
    
	//Optimize image
	image = SDL_DisplayFormat(temp);

	// Clean up
	SDL_FreeSurface(temp);

	// Set alpha flags
	SDL_SetAlpha(image, SDL_SRCALPHA, SDL_ALPHA_OPAQUE);
	image->format->Amask = 0xFF000000;
    
    //Return the optimized image
    return image;
}

// loads text onto surface
SDL_Surface* loadtext(std::string fontname, int size, std::string words) {
	// load font at size
	TTF_Font* font = TTF_OpenFont(fontname.c_str(),size);
	// declare black font
	SDL_Color fontcolor = {0, 0, 0};
	// create surface with font paremeters
	SDL_Surface* menutext = TTF_RenderText_Blended(font, words.c_str(), fontcolor );

	// clean
	TTF_CloseFont(font);

	return menutext;
}

// overload to handle font color in format {r,g,b}
SDL_Surface* loadtext(std::string fontname, int size, SDL_Color fontcolor,std::string words) {
	// load font at size
	TTF_Font* font = TTF_OpenFont(fontname.c_str(),size);
	// create surface with font paremeters
	SDL_Surface* menutext = TTF_RenderText_Blended( font, words.c_str(), fontcolor );
	
	// clean
	TTF_CloseFont(font);
	
	return menutext;
}