public class Application {
  private ClockView view;
  private ClockModel model;
  private ClockController controller;
  MainWindow window;

  public Application() {
    model= new ClockModel();
    view= new ClockView(model);
    controller = new ClockController(model, view);
    window = new MainWindow(view);
    window.setController(controller);
  }

  public void show() {
    window.setVisible(true);
  }

  public static void main(String[] args) {
    Application app = new Application();
    app.show();
  }
}