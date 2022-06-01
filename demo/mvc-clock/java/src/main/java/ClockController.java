import java.awt.* ;
import java.awt.event.* ;
import javax.swing.* ;

public class ClockController extends JFrame {
	private ClockView view;
	private ClockModel model;

  public ClockController(ClockModel m, ClockView v) {
		model = m;
		view = v;
  }

  public void tick() {
    model.advance();
    view.repaint();
  }

  public void reset() {
    model.init();
    view.repaint();
  }
}