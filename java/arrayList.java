import java.util.*;

  
public class Main  {

	public static void main(String args[]){
	   ArrayList<Student> arraylist = new ArrayList<Student>();
	   arraylist.add(new Student(101, "Zues", 26));
	   arraylist.add(new Student(505, "Abey", 24));
	   arraylist.add(new Student(809, "Vignesh", 32));

    Iterator<Student> iter = arraylist.iterator();
    
        System.out.println("\nThe iterator values of list are: ");
        while (iter.hasNext()) {
            System.out.print(iter.next().studentname + " ");
        }
	}
}
class Student  {
     String studentname;
     int rollno;
     int studentage;

    public Student(int rollno, String studentname, int studentage) {
        this.rollno = rollno;
        this.studentname = studentname;
        this.studentage = studentage;
}}
