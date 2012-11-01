/*
   Copyright 2012 Alexander Diana, Jeff Carey, Alexander Keller

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#define FPS 32
#include <time.h>
#include <sstream>

// Use inbuilt linux headers, as SDL redclares things which are
// preincluded in linux, also X11 would b0rk with windows gfx libs.
#ifdef OS_WINDOWS
	#include "include/SDL.h"
	#include "include/SDL_ttf.h"
	#include "include/SDL_rotozoom.h"
#else
	#include <SDL/SDL.h>
	#include <SDL/SDL_ttf.h>
	#include <SDL/SDL_rotozoom.h>
#endif

#include "utils.h"
#include "imgload.h"
#include "screenutils.h"
#include "init.h"

int main (int argc, char *argv[]) {
}