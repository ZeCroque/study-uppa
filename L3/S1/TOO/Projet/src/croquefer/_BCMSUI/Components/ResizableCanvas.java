package croquefer._BCMSUI.Components;

import croquefer._BCMSUI.Utilities.Route;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;

public class ResizableCanvas extends Canvas
{
	private Route currentRoute;
	
	public ResizableCanvas(Route r) 
	{
		super();
		this.currentRoute=r;
		//this.drawRoute();
        widthProperty().addListener(evt -> draw());
    }
	
	@Override
	public boolean isResizable()
	{
		return true;
	}
	
	public void setRoute(Route r)
	{
		this.currentRoute=r;
		//this.drawRoute();
	}
	
 
	private void draw() 
	{
		double height = getHeight();
		double width = getWidth();
		GraphicsContext gc = getGraphicsContext2D();
		gc.setStroke(Color.BLUE);
		gc.clearRect(0, 0, width, height);
        gc.strokeRect((width-height)/2, 0, height, height);
		
        drawRoute();

    }
	
	private void drawRoute()
	{
		double height = getHeight();
		double width = getWidth();
		GraphicsContext gc = this.getGraphicsContext2D();
		gc.setStroke(Color.RED);
		gc.clearRect(0, 0, width, height);
        gc.strokeRect(150, 150,40, 40);
		
		
		
		
		int i=this.currentRoute.getStartPoint().getKey();
		int j=this.currentRoute.getStartPoint().getValue();
		boolean[][] tempMatrix=currentRoute.getMatrix();
		System.out.println(this.currentRoute);
		System.out.println("start("+this.currentRoute.getStartPoint().getKey()+","+this.currentRoute.getStartPoint().getValue()+")");
		System.out.println("end("+this.currentRoute.getEndPoint().getKey()+","+this.currentRoute.getEndPoint().getValue()+")");
		do
		{
			if(i<tempMatrix.length-1 && tempMatrix[i+1][j])
			{
				tempMatrix[i][j]=false;
				i++;
				drawHorizontalLine(i, j, true);
			}
			else if(i>0 && tempMatrix[i-1][j])
			{
				tempMatrix[i][j]=false;
				i--;
				drawHorizontalLine(i, j, false);
			}
			else if(j<tempMatrix.length-1 && tempMatrix[i][j+1])
			{
				tempMatrix[i][j]=false;
				j++;
				drawVerticalLine(i, j, true);
			}
			else if(j>0 && tempMatrix[i][j-1])
			{
				tempMatrix[i][j]=false;
				j--;
				drawVerticalLine(i, j, false);
			}			
		} while(i!=this.currentRoute.getEndPoint().getKey() || j!=this.currentRoute.getEndPoint().getValue());
	}
	
	private void drawHorizontalLine(int x, int y, boolean direction)
	{
		double height = getHeight();
		double width = getWidth();
		double xStart=(width-height)/2+10+x*((height-20)/10);
		double yStart=y*((height-20)/10)+10;
		GraphicsContext gc = getGraphicsContext2D();
		gc.setStroke(Color.BLACK);
		if(direction)
		{
	        gc.strokeLine(xStart, yStart, xStart+((height-20)/10), yStart);
		}
		else
		{
			gc.strokeLine(xStart, yStart, xStart-((height-20)/10), yStart);
		}	
	}
	
	private void drawVerticalLine(int x, int y, boolean direction)
	{
		double height = getHeight();
		double width = getWidth();
		double xStart=(width-height)/2+10+x*((height-20)/10);
		double yStart=y*((height-20)/10)+10;
		GraphicsContext gc = getGraphicsContext2D();
		gc.setStroke(Color.BLACK);
		if(direction)
		{
	        gc.strokeLine(xStart, yStart, xStart, yStart+((height-20)/10));
		}
		else
		{
			gc.strokeLine(xStart, yStart, xStart, yStart-((height-20)/10));
		}	
	}
}