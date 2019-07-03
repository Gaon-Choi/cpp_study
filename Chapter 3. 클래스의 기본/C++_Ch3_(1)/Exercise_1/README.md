# Exercise 1

A struct which can represent location in double-dimensional flat is as follows.

```cpp
struct Point {
  int xpos;
  int ypos;
};
```

We want to define this following functions based on the struct Point.

(Detailed function is in the example of the implementation.)

```cpp
void MovePos(int x, int y);
void AddPoint(const Point &pos);
void ShowPosition();
```

However, you need to make a main function and then define the above functions in the struct.

```cpp
int main(void) {
  Point pos1={12, 4};
  Point pos2={20, 30};

  pos1.MovePos(-7, 10);
  pos1.ShowPosition();  // prints [5, 14]

  pos1.AddPoint(pos2);
  pos1.ShowPosition();  // prints [25, 44]
  return 0;
}
```

And as shown in the comments above, Functions need to be defined so that the results are like the following.

*[Example]*
[5, 14]
[25, 44]
