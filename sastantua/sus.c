#include <stdio.h>
#include <unistd.h>

void ft_putchar(char ch)
{
    write(1, &ch, 1);
}

int print_block (int block_height, int block_top_width, int spaces)
{
  int block_top_width_copy;
  int spaces_copy = spaces;

  block_top_width_copy = block_top_width;
  while (block_height > 0)
  {
    while (spaces_copy-- >= 0)
      ft_putchar(' ');
    ft_putchar('/');
    while (block_top_width_copy-- >= 0)
      ft_putchar('*');
    block_top_width += 2;
    block_top_width_copy = block_top_width;
    ft_putchar('\\');
    ft_putchar('\n');
    block_height--;
    spaces--;
    spaces_copy = spaces;
  }
  return(block_top_width - 1);
}

int print_block_with_door (int block_height, int block_top_width, int spaces, int door_height)
{
  int block_top_width_copy;
  int spaces_copy = spaces;
  int block_top_width_copy_copy;
  int iter;
  int iter_2;
  int block_height_copy;

  iter = 0;
  block_height_copy = block_height;
  while (block_height > 0)
  {
    iter_2 = door_height;
    block_top_width_copy = block_top_width / 2 - 1;
    block_top_width_copy_copy = block_top_width_copy + 2;
    while (spaces_copy-- >= 0)
      ft_putchar(' ');
    ft_putchar('/');
    while (block_top_width_copy-- >= 0)
      ft_putchar('*');
    if (iter >= block_height_copy - door_height)
    {
      block_top_width_copy_copy -= door_height / 2 + 1;
      block_top_width_copy -= block_top_width_copy_copy;
      while (iter_2-- > 0)
        ft_putchar('|');
    }
    iter ++;
    while (block_top_width_copy_copy-- > 0)
      ft_putchar('*');
    block_top_width += 2;
    ft_putchar('\\');
    ft_putchar('\n');
    block_height--;
    spaces--;
    spaces_copy = spaces;
  }
  return(block_top_width - 1);
}

void sastantua(int size)
{
  int door_height = 1;
  int door_width = 1;
  int pyr_height = size;
  int block_top_width;
  int bottom_block_width = 5;
  int bottom_block_height = size + 2;
  int i = 12;
  int size_copy = size - 1;
  int iter_adder = 0;
  int iter_of_size = size;  
  int iter_copy = iter_of_size;
  int current_lvl = 1;
  int block_height = 3;
  int spaces = 0;
  int incresing_width = 5;
  int space_decreaser = 2;

  while (size_copy > 0)
  {
    bottom_block_width += i;
    i += 2;
    iter_adder += 1;
    size_copy--;

    if (iter_adder == 2)
    {
      door_height += 2;
      iter_adder = 0;
      i += 2;
    }
  }
  iter_adder = 0;
  spaces = bottom_block_width / 2;
  while (iter_copy > 1)
  {
    bottom_block_width = print_block(block_height, block_top_width, spaces);

    spaces -= (block_height);
    block_height++;
    iter_copy--;
    if (iter_adder == 2)
    {
      iter_adder = 0;
      incresing_width += 2;
      space_decreaser += 1;
    }
    spaces -= space_decreaser;
    iter_adder++;
    block_top_width = bottom_block_width + incresing_width;
  }
  print_block_with_door(block_height, block_top_width, spaces, door_height);
  
}
int main()
{
    sastantua(10);

    return 0;
}
