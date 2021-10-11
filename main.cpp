#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

string array_to_string(int argc, char** array, string inbetween);
string get_tree(int percent, int stop_time);

int main(int argc, char** argv) {
  time_t start_time = time(NULL);
  int stop_time;
  istringstream(array_to_string(argc, argv, "")) >> stop_time;
  int percent = (time(NULL)-start_time);
  string last_printed;
  string print = get_tree(percent, stop_time);
  while (percent < stop_time) {
    print = get_tree(percent, stop_time);
    if (last_printed != print) {
      printf("\033[2J");
      printf("\033[%d;%dH", 0, 0);
      cout << print << flush;
      last_printed = print;
    }
    percent = (time(NULL)-start_time);
  }
  printf("\033[2J");
  printf("\033[%d;%dH", 0, 0);
  cout << "                     &   &&\n                 &  &&  & &\n              &&&& &&&& &   &\n                 &&&&&/&&&\n                 && |/&\n                   \\|\n        & &         |/       &&\n        &&&&& &&   \\|      && && &    &\n          &&&&~&& & |/ __/ && &&&&&& &\n        & &&&&& &  \\|/    / _/_/&&&&&&\n     &&&&& &/& &&  \\/~         &/&_/\n&&&&& &&&&&& \\| &   |/           &\n&&&&_\\_&| &   /~/  \\|           &\n  & & & \\_&  \\/|\\   /~\n    &     \\__ /~_|//~\n            \\/|/~\n            /~|/\n            \\/~\n             //_/_/  /_/  _&/_&&&&&&  &\n               //___/   / _&&&&&&&& &\n:___________./~~~\\.___________:\n \\                           /\n  \\_________________________/\n  (_)                     (_)\n" << flush;
}

string array_to_string(int argc, char** array, string inbetween) {
  ostringstream stream;
  for (int i = 1; i < argc; ++i) {
    if (i-1) stream << inbetween;
    stream << array[i];
  }
  return stream.str();
}

string get_tree(int percent, int stop_time) {
  if (percent < (stop_time/3)) {
    return "               && &\n         &&   & &&&&&&&\n        &  &&&/~/&&& &\n:___________./~~~\\.___________:\n \\                           /\n  \\_________________________/\n  (_)                     (_)";
  }
  else if (percent < ((stop_time/3)*2)) {
    return "                &\n             &  &&\n         &  &&&&&&&&&\n         &&&&&&&~&&&\n        && &&&|&&/&  &\n        &&&&  &/~|/|\n       &&&&    &\\\\\\_\n              //~/~\n:___________./~~~\\.___________:\n \\                           /\n  \\_________________________/\n  (_)                     (_)";
  }
  else {
    return "                    &&\n                 &&&&&&/&\n            &&&  &/ &&/&&\n      && & &&&&&\\|&&&|&&\n      && &&&&&&&&&&&&&&&\n& &&  &&&&&   |&/|\\ &\\&\n&&&    &/|&& |/ /|\\   |/\n&   &&&&&&&_/~  /|\\  |/\n       & &&\\||\\\\_~|/~\\\n            \\_\\  /|/~\n              /|/~/~/    &&&\n             /~\\/~\\ /    &&&&&& &\n                //~|\\ __&&&&&&&\n                /~/~     &&& & &\n   :___________./~~~\\.___________:\n    \\                           /\n     \\_________________________/\n     (_)                     (_)";
  }
}
