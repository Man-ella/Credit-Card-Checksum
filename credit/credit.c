#include <cs50.h>
#include <stdio.h>

int main(void)
{
   //Prompt user input
  unsigned long userInput = get_long("Enter card number: ");
  
   //Calculate checksum

   unsigned long divisor = 10;
   unsigned long count = 0;
   unsigned long dividend = userInput;
   int remainder=0;
   int previous=0;
   unsigned long oddSum = 0;
   unsigned long evenSum = 0;
   unsigned long evenMultiple = 0;
   string status;
   while (dividend != 0)
   {
      previous = remainder;
      remainder = dividend % divisor;
      dividend /= divisor;
      count++;
      // printf("remainder = %i\n", remainder);
      // printf("count = %li\n", count);

      //sum of every other digit starting from last digit

      if (count % 2 == 1)
      {
         oddSum += remainder;
      }

      //sum of the digits of the products of every other digit starting from the second to last digit
      else
      {
         evenMultiple = remainder * 2;
         if (evenMultiple / 10 > 0)
         {
            evenSum = evenSum + 1 + (evenMultiple % 10); // adding the digits of products >= 10
         }
         else
         {
            evenSum += evenMultiple; // adding the digits of products < 10
         }

      }
   }

   unsigned long total = oddSum + evenSum;
   int checksum;
   if (total % 10 == 0) checksum = 1; //1 for correct
   else checksum = 0; //0 for wrong

   //Check card length and start digit(s)

   if (checksum == 0)
   {
      status = "INVALID";
   }

   else
   {
      if ((count == 13 || count == 16) && (remainder == 4))
      {
         status = "VISA";
      }
      else if ((count == 15) && (remainder == 3) && (previous == 4 || previous == 7))
      {
         status = "AMEX";
      }
      else if ((count == 16) && (remainder == 5) && (previous >= 1 && previous <= 5))
      {
         status = "MASTERCARD";
      }
      else
      {
         status = "INVALID";
      }
   }

   //Print kind of card / invalid

   printf("%s\n", status);
}

