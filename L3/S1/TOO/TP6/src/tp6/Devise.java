/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp6;

/**
 *
 * @author gcroquefer
 */
public abstract class Devise 
{
    protected String symbole;
    protected String nom;
    
    public abstract double conversion(double montant, Devise devise); 
    public abstract String getNom();
}
