import java.util.Scanner;
 
class AgeException extends Exception {
 
 public AgeException(String str) {
  System.out.println(str);
 }
}
public class AgeExcDemo {
 
 public static void main(String[] args) {
  Scanner s = new Scanner(System.in);
  System.out.print("Enter ur age :: ");
  int age = s.nextInt();
  
  try {
   if(age < 18) 
    throw new AgeException("Invalid age");
   else
    System.out.println("Valid age");
  }
  catch (AgeException a) {
   System.out.println(a);
  }
 }
}

/*
OUTPUT 1
C:\>javac AgeExcDemo.java
C:\>java AgeExcDemo
Enter ur age :: 15
Invalid age
exception.AgeException
OUTPUT 2
C:\>javac AgeExcDemo.java
C:\>java AgeExcDemo
Enter ur age :: 20
Valid age
