import java.awt.* ;
import java.awt.geom.*;
import javax.swing.* ;

public class ClockView extends JPanel {
  private ClockModel model;

  public ClockView(ClockModel m) {
      model = m;
  }

  private void paintClock(Graphics g) {
    Graphics2D g2= (Graphics2D)g;
    int hours = model.getHours();
    int minutes= model.getMinutes();
    int seconds = model.getSeconds();
    Shape e= new Ellipse2D.Double(100, 20, 160, 160);
    g2.draw(e);
    double hourAngle = 2 * Math.PI * (hours - 3) / 12;
    double minuteAngle = 2 * Math.PI * (minutes - 15) / 60;
    double secondAngle = 2 * Math.PI * (seconds - 15) / 60;
    Line2D.Double hour_line =
        new Line2D.Double(180, 100,
                          180 + (int) (30 * Math.cos(hourAngle)),
                          100 + (int) (30 * Math.sin(hourAngle)));
    Line2D.Double minute_line =
        new Line2D.Double(180, 100,
                          180 + (int) (46 * Math.cos(minuteAngle)),
                          100 + (int) (46 * Math.sin(minuteAngle)));
    Line2D.Double second_line =
        new Line2D.Double(180, 100,
                          180 + (int) (60 * Math.cos(secondAngle)),
                          100 + (int) (60 * Math.sin(secondAngle)));
    g2.draw(hour_line);
    g2.draw(minute_line);
    g2.draw(second_line);
  }

	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		paintClock(g);
	}
}