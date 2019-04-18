import java.awt.*;
import java.util.*;
import javax.swing.*;
import java.time.*;

public class analogClock extends JPanel
{
  public void paintComponent(Graphics g)
  {
      int divx[],divy[],div,second,secondx,secondy,minutex,minutey,minute,hourx,houry,hour,flag;
      flag = 0;
      double angle,angleSec,angleMin,angleHr,temp;
      String Time;
      divx = new int[12];
      divy= new int[12];
      div=12;
      int numbers[] = {12,1,2,3,4,5,6,7,8,9,10,11};
      Color clockbg = new Color(127,255,212);
      super.paintComponent(g);
      Graphics2D g2 = (Graphics2D) g;
      g.setColor(clockbg);
      g.fillOval(150,150,350,350);
      Color oval = new Color(0,26,77);
      g.setColor(oval);
      g.fillOval(323,325,5,5);
      Color time = new Color(0,26,77);
      g.setColor(time);
      g.setFont(new Font("verdana", Font.BOLD, 12));
      for(int i=0;i<div;i++)
      {
        angle = i*(360/div)-90;
        divx[i] = (int)(160 * Math.cos(Math.toRadians(angle)));
        divy[i] = (int)(160 * Math.sin(Math.toRadians(angle)));
        g.drawString(Integer.toString(numbers[i]),divx[i]+322,divy[i]+330);
      }
        second = LocalDateTime.now().getSecond();
        minute =  LocalDateTime.now().getMinute();
        hour = LocalDateTime.now().getHour();
        if(hour > 12 )
        {
          hour = hour - 12;
          flag = 1;
        }
        angleSec = (6 * second) - 90;
        angleMin = (6 * minute) - 90;
        angleHr = ((30 * hour) + (minute * 0.5)) - 90;
        secondx = (int)(160 * Math.cos(Math.toRadians(angleSec)));
        secondy = (int)(160 * Math.sin(Math.toRadians(angleSec)));
        Color sechand = new Color(255, 77, 148);
        g.setColor(sechand);
        g.drawLine(325,325,secondx+325,secondy+325);
        minutex = (int)(160 * Math.cos(Math.toRadians(angleMin)));
        minutey = (int)(160 * Math.sin(Math.toRadians(angleMin)));
        g2.setStroke(new BasicStroke(2));
        Color minhand = new Color(51, 102, 153);
        g.setColor(minhand);
        g.drawLine(325,325,minutex+325,minutey+325);
        hourx = (int)(160 * Math.cos(Math.toRadians(angleHr)));
        houry = (int)(160 * Math.sin(Math.toRadians(angleHr)));
        g2.setStroke(new BasicStroke(4));
        Color hrhand = new Color(0, 89, 179);
        g.setColor(hrhand);
        g.drawLine(325,325,hourx+325,houry+325);
        g.setFont(new Font("verdana", Font.BOLD, 16));
        Color ampm = new Color(0, 128, 128);
        g.setColor(ampm);
        if(flag == 0)
        {
          g.drawString("AM",310,410);
        }
        else
        {
          g.drawString("PM",310,410);
        }
}
  public static void main(String[] args) {
    JFrame frame = new JFrame("Analog Clock");
    while(true)
    {
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      frame.setBackground(Color.red);
      frame.setSize(700, 700);
      analogClock panel = new analogClock();
      frame.add(panel);
      frame.setVisible(true);
    }
  }
}
