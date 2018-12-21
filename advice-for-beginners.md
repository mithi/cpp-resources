### Here's a simple example based on what you're trying to do: 
- https://gist.github.com/mithi/1e94d4092aea217e3defa5d89ced27a5

### You can test how it works here: 
- https://www.onlinegdb.com/online_c++_compiler

### THE CODE
```cpp
#include <iostream>
#include <sstream>
using namespace std;

int main(){

  string path = "/home/soham/wow/src/my_pcl_tutorial/b2k/frame"; 
  string file_extension = ".pcd";
  
  string file1;
  string file2;
  stringstream s;

  for (int i = 0; i < 10; i++) {

    s << path << i << file_extension << " ";
    s << path << i + 1 << file_extension << " ";
    s >> file1;
    s >> file2;
    
    cout << "\niteration:" << i + 1;
    cout << "\n--> " << file1 << "\n--> " << file2 << "\n";
  }

  s.clear();
  file1.clear();
  file2.clear();
  return 0;
}
```

### If you do things correctly: 
```
--> /home/soham/wow/src/my_pcl_tutorial/b2k/frame0.pcd                                                                  
--> /home/soham/wow/src/my_pcl_tutorial/b2k/frame1.pcd                                                                  
                                                                                                                        
iteration:2                                                                                                             
--> /home/soham/wow/src/my_pcl_tutorial/b2k/frame1.pcd                                                                  
--> /home/soham/wow/src/my_pcl_tutorial/b2k/frame2.pcd

.
.
.
iteration:10                                                                                                            
--> /home/soham/wow/src/my_pcl_tutorial/b2k/frame9.pcd                                                                  
--> /home/soham/wow/src/my_pcl_tutorial/b2k/frame10.pcd  
```

# ALL MY SUGGESTIONS STILL STAND. 
1. Try to do it on your own. It's very important that you do the work yourself, so that you will learn from the experience. 
2. Read the documentation 
3. Start with something small, compile and execute. Add a little more code, compile and execute again. Always check if it's doing what you expect it to every time you add a small piece of code. Start with a small code and built your way up from there. Start with small intentions.
4. Another thing all professional programmers do is to break down their code into smaller digestible functions. If there's one thing all experienced programmers hate it's the God Method. See also: http://wiki.c2.com/?GodMethod
5. You might also be interested in learning about rubber ducky programming: https://rubberduckdebugging.com/
6. You should practice how to ask questions the smart way. This is a must read: 
- http://www.catb.org/esr/faqs/smart-questions.html
7. Readability matters. For a start, you should indent your code properly so that it's easier to read and debug. I recommend to use two spaces for indentation and that the first curly brace should be on the the same line of the method. Also whatever code style you adopt it is important to be consistent with your code style. 
```c++
int main() {
  cout << "hello world!";
}
```
- You can read more here:
  -  https://blog.programminghub.io/blog/2017/06/07/importance-indentation-programming/ . 
- You can also look at my code for an example of proper indentation:
  - https://github.com/mithi/highway-path-planning/blob/master/BOSCH-CHALLENGE/src/vehicle.cpp
