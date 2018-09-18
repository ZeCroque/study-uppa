package tp1;
import java.util.Scanner;
/**
 *
 * @author gcroquefer
 */
public class N_INSEE {


    public static void main(String[] args) 
    {

        Scanner sc = new Scanner(System.in);

        long userINSEE;
        int userKey = 0;
        long calculatedKey;
        
 	System.out.println("Entrer un INSEE"); 
 	userINSEE = Long.parseUnsignedLong(sc.nextLine());
        System.out.println("Entrer la clé"); 
 	userKey = Integer.parseInt(sc.nextLine());

        
        calculatedKey = 97 - (userINSEE%97);
        
        if (userKey==calculatedKey)
        {
            System.out.println("Le numéro est valide");
        }
        
        sc.close();
        
        
    }
    
}
