/*
  เขียนโปรแกรมรับ input เป็นชุดตัวเลขเรียงลำดับจากน้อยไปมา 2 ชุด แล้วแสดงผลเป็นชุดตัวเลขที่เรียงลำดับจากน้อยไปมาก ของตัวเลขภายใน input ทั้งสองชุด

input :
3 8 14 23 56
1 2 9 18 22 89
output :
1 2 3 8 9 14 18 22 23 56 89
  */

#include <stdio.h>
#include <math.h>

int IsNum(int index, char string[100]);
int GetGlobLength(int fromIndex, char string[100]);
int StringToInt(int fromIndex, int Length, char string[100]);
int CharToInt (int index, char string[100]);

int main(void)
{
  char input1[100], input2[100];
  int num1[50], num2[50];

  fgets(input1, 100, stdin);
  fgets(input2, 100, stdin);

  int input1cursor = 0, input2cursor = 0;
  int num1index = 0, num2index = 0;

  // for (int i = 0; i < 40; i++)
  // {
  //   if (input1[input1cursor] > input2[input2cursor])
  //   {
  //     printf("%d", input1[input1cursor]);
  //     input1cursor++;
  //   }
  //   else
  //   {
  //     printf("%d", input2[input1cursor]);
  //     input2cursor++;
  //   }
  // }
  
  while (input1[input1cursor] != '\n')
  {
    if (IsNum(input1cursor, input1) == 1) {
      int globLength = GetGlobLength(input1cursor, input1);
      int value = StringToInt(input1cursor, globLength, input1);
      num1[num1index] = value;
      input1cursor += globLength + 1;
      num1index++;
    }
    else {
      input1cursor++;
    }
  }

  while (input2[input2cursor] != '\n')
  {
    if (IsNum(input2cursor, input2) == 1) {
      int globLength = GetGlobLength(input2cursor, input2);
      int value = StringToInt(input2cursor, globLength, input2);
      num2[num2index] = value;
      input2cursor += globLength + 1;
      num2index++;
    }
    else {
      input2cursor++;
    }
  }

  
}

int IsNum(int index, char string[100])
{
  char charAtIndex = string[index];
  if (charAtIndex >= '0' && charAtIndex <= '9')
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int GetGlobLength(int fromIndex, char string[100])
{
  int globLength = 0;
  while (IsNum(fromIndex + globLength, string) == 1)
  {
    if (IsNum(fromIndex + globLength + 1, string) == 1)
    {
      globLength++;
    }
    else
    {
      break;
    }
    // DEBUGWATCH globLength after loop
  }
  return globLength;
}

int StringToInt(int fromIndex, int Length, char string[100])
{
  int coefficient = Length;
  int sum = 0;
  for (int i = fromIndex; i <= fromIndex + Length; i++)
  {
    int digitValue = CharToInt(i, string);
    int valueWithCoefficient = ((int)(pow(10, coefficient))) * digitValue;
    sum += valueWithCoefficient;
    coefficient--;
    // DEBUGWATCH digitValue valueWithCoefficient sum; after loop
  }
  return sum;
}

int CharToInt (int index, char string[100]) {
    int result = (string[index]) - '0';
    // DEBUGWATCH result
    return result;
}
