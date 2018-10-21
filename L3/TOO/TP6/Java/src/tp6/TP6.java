package tp6;

/**
 *
 * @author gcroquefer
 */
public class TP6 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        Euro euro=new Euro();
        Dollar dollar=new Dollar();
        Yuan yuan=new Yuan();
        
        
        System.out.println(euro.conversion(1.0, dollar));
        System.out.println(euro.conversion(1.0, yuan));
    }
    
}
