import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
public class CSV {
  public static void main(String[] args) {
    String line = "";
    String splitBy = ",";
    
      //parsing a CSV file into BufferedReader class constructor  
      BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\Dell\\Desktop\\csvDemo.csv"));
      while ((line = br.readLine()) != null)
      //returns a Boolean value  
      {
        String[] employee = line.split(splitBy);
        //use comma as separator  
        System.out.println("Emp[First Name=" + employee[1] + ", Last Name=" + employee[2] + ", Contact=" + employee[3] + ", City= " + employee[4] + "]");
      }
    
  }
}
