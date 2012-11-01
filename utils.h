/*
Created by Alexander Diana (Student Number: 100458717)
		   Jeff Carey      (Student Number: 100451635)
*/

// convert int to string
std::string str(int number)
{
   std::stringstream ss;
   ss << number;
   return ss.str();
}

int getticks() {return SDL_GetTicks();}