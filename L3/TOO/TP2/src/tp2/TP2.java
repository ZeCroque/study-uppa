package tp2;

import java.util.Calendar;
import java.util.Scanner;
/**
 *
 * @author gcroquefer
 */
public class TP2 
{

    public static void main(String[] args) 
    {
        int year=0;
        Scanner sc=new Scanner(System.in);
        
        System.out.println("Entrez une année");
        year=Integer.parseInt(sc.nextLine()); 
        
        System.out.println("Via int:\nL'année "+year+" est bissextile?\n"+anneeBissextileInt(year)); 

        Calendar now = java.util.Calendar.getInstance();
        System.out.println("Via calendar:\nL'année "+now.get(Calendar.YEAR)+" est bissextile?\n"+anneeBissextileCalendar(now));
        sc.close();
    }
    
    private static boolean anneeBissextileInt(int year)
    {
        return ((year%4==0 && year%100!=0) || year%400==0);
    }
    
    private static boolean anneeBissextileCalendar(Calendar date)
    {
        int year = date.get(Calendar.YEAR);   
        return ((year%4==0 && year%100!=0) || year%400==0);

    }
    
}
