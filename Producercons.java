/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package producercons;

/**
 *
 * @author Student
 */
import java.util.ArrayList;
import java.util.List;
public class Producercons {

    public static void main(String[] args) {
     List <Integer> b=new ArrayList <Integer>();
     Thread p=new Thread(new producer(b));
     Thread c=new Thread(new consumer(b));
     p.start();
     c.start();
     }
   }
class producer implements Runnable
{
    List <Integer> b = null;
    private int i=0;
    final int maxs=5;
    producer(List<Integer> b)
    {
     this.b=b;
    }
    public void produce(int i)throws InterruptedException
    {
        synchronized(b)
                {
                    while(b.size()==maxs)
                    {
                       System.out.println("p is waiting");
                       b.wait();
                    }
                }
        synchronized (b)
        {
            b.add(i);
            System.out.println("poducer is producing");
            Thread.sleep(300);
            b.notify();
        }
                
    }
    public void run()
    {
        try
        {
            while(true)
            {
                i++;
                produce(i);
                
            }
        }
        catch(InterruptedException ex)
        {
            System.out.println("system interrupted");
        }
    }
}


class consumer implements Runnable
{
    List <Integer> b = null;
  
    consumer(List<Integer> b)
    {
     this.b=b;
    }
    public void consume()throws InterruptedException
    {
        synchronized(b)
                {
                    while(b.isEmpty())
                    {
                       System.out.println("consumer is waiting");
                       b.wait();
                    }
                }
        synchronized (b)
        {
            b.remove(0);
            System.out.println("consumer  is consuming");
            Thread.sleep(300);
            b.notify();
        }
                
    }
    public void run()
    {
        try
        {
            while(true)
            {
                
                consume();
                
            }
        }
        catch(InterruptedException ex)
        {
            System.out.println("system interrupted");
        }
    }
}
