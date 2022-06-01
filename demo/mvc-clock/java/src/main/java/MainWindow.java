import java.awt.* ;
import java.awt.event.* ;
import javax.swing.* ;

class MainWindow extends JFrame {
  private JButton tickButton, resetButton;
  private JPanel buttonHolder;
  private Container contentPane;
  private ClockController controller;

  public MainWindow(ClockView clock_view) {
    contentPane = getContentPane();
    setSize(350, 270);
    setTitle("MVC Clock");
    buttonHolder = new JPanel();
    contentPane.add(buttonHolder, BorderLayout.SOUTH);

    tickButton = new JButton("Tick");
    resetButton = new JButton("Reset");

    buttonHolder.add(tickButton);
    buttonHolder.add(resetButton);

    contentPane.add(clock_view, BorderLayout.CENTER);
    tickButton.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent ae) {
        controller.tick();
      }
    });

    resetButton.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent ae) {
        controller.reset();
      }
    });

    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
  }

  public void setController(ClockController controller) {
    this.controller = controller;
  }
}