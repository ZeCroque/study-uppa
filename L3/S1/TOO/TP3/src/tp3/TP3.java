package tp3;

/**
 *
 * @author gcroquefer
 */

import java.util.Calendar;
import java.util.Scanner;

public class TP3 
{
    public static String unknown = "Je ne sais pas quand c'est";
    public static String avant_hier = "Avant-hier";
    public static String hier = "Hier";
    public static String aujourdhui = "Aujourd'hui";
    public static String demain = "Demain";
    public static String apres_demain = "Après-Demain";
    
    public static void main(String[] args) 
    {
        Calendar now=Calendar.getInstance();
        int day=0;
        int month=0;
        int year=0;
        Scanner sc = new Scanner(System.in);
        String result="Erreur";
        
        System.out.println("Entrez le jour :");
        day=Integer.parseInt(sc.nextLine());
        System.out.println("Entrez le mois (nombre):");
        month=Integer.parseInt(sc.nextLine());
        System.out.println("Entrez l'année :");
        year=Integer.parseInt(sc.nextLine());
        System.out.println(dateCompare(day, month, year, now));
        
    }
    
    public static String dateCompare(int day, int month, int year, Calendar date)
    {
        String result=unknown;
        
        if (year == date.get(Calendar.YEAR))
        {
            if (month == date.get(Calendar.MONTH)+1) 
            {       
               if (day == (date.get(Calendar.DAY_OF_MONTH) - 2))
               {
                  result= avant_hier; 
               }
               else if (day == (date.get(Calendar.DAY_OF_MONTH) - 1))
               {
                  result= hier; 
               }
               else if (day == (date.get(Calendar.DAY_OF_MONTH)))
               {
                  result= aujourdhui; 
               }
               else if (day == (date.get(Calendar.DAY_OF_MONTH)+1))
               {
                  result= demain; 
               }
               else if (day == (date.get(Calendar.DAY_OF_MONTH)+2))
               {
                  result= apres_demain; 
               }
            }
   
        }
        
        return result;
    }
    
}