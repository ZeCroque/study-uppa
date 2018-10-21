package tp5;

public class Temperature 
{
	
	//STATIC
	public static final double _minCelsius=-273.15;
	public static final char[] _units= {'K','C','F'};
	
	
	//INSTANCE
	private double _temperature;
	private double _step;
	
	public Temperature()
	{
		this._temperature=0;
		this._step=0.001;
	}
	
	public Temperature(double value, char unit)
	{
		this._step=0.001;
		
		boolean knownUnit=false;
		for(char units:_units)
		{
			if(units==unit)
			{
				knownUnit=true;
				break;
			}
		}
		if(!knownUnit)
		{
			System.out.println("Unité non connue, instanciation par défaut.");
			return;
		}
		else
		{
			switch(unit)
			{
				case 'K':
					if(value<0)
					{
						System.out.println("Valeur inférieure au zéro absolu, instanciation par défaut.");
						return;
					}
					this._temperature=value;
					break;
				case 'C':	
					if(value-_minCelsius<0)
					{
						System.out.println("Valeur inférieure au zéro absolu, instanciation par défaut.");
						return;
					}
					this._temperature=value-_minCelsius;
					break;
				case 'F':
					if((value-32.)/(9./5.)-_minCelsius<0)
					{
						System.out.println("Valeur inférieure au zéro absolu, instanciation par défaut.");
						return;
					}
					this._temperature=(value-32.)/(9./5.)-_minCelsius;
					break;
			}
		}

	}
	
	public void setStep(double step)
	{
		this._step=step;
	}
	
	public double getStep()
	{
		return this._step;
	}
	
	public void increment()
	{
		this._temperature+=this._step;
	}
	
	public void decrement()
	{
		this._temperature-=this._step;
	}
	
	public double getAsKelvin()
	{
		return this._temperature;
	}
	
	public double getAsCelsius()
	{
		return this._temperature+_minCelsius;
	}
	
	public double getAsFahrenheit()
	{
		return 9./5. * this.getAsCelsius() + 32.;
	}
	
}
