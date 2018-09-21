/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Exam
 */

import java.io.Reader;
import java.util.concurrent.Semaphore;
import java.util.logging.Level;
import java.util.logging.Logger;
public class RW {
    static int rc=0;
    static Semaphore s=new Semaphore(1);
    
    static Semaphore wrt=new Semaphore(2);
    static class reader implements Runnable
    {
        public void run()
        {
            try {
                s.acquire();
                rc=rc+1;
                if(rc==1)
                    wrt.acquire();
                s.release();
                System.out.println(Thread.currentThread().getName()+"is reading");
                Thread.sleep(500);
                s.acquire();
                        rc=rc-1;
                        if(rc==0)
                            wrt.release();
                        s.release();
            } catch (InterruptedException ex) {
                Logger.getLogger(RW.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
    static class writer implements Runnable
    {
        public void run()
        {
            try {
                wrt.acquire();
                System.out.println(Thread.currentThread().getName()+"is writing");
                Thread.sleep(500);
                wrt.release();
            } catch (InterruptedException ex) {
                Logger.getLogger(RW.class.getName()).log(Level.SEVERE, null, ex);
            }
    }
}
    public static void main(String[] args) {
        reader r =new reader();
         writer w =new writer();
        Thread t1=new Thread(r);
        t1.setName("t1");
        t1.start();
        Thread t2 = new Thread(w);
        t2.setName("t2");
        t2.start();
        Thread t3 = new Thread(r);
        t3.setName("t3");
        t3.start();
    }
}