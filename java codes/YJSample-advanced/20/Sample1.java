import java.awt.*;
import javax.swing.*;

public class Sample1 extends JApplet
{
   private JLabel lb;
   private JButton bt;

   public void init()
   {
      // 建立元件
      lb = new JLabel("歡迎光臨。");
      bt = new JButton("購買");

      // 設定容器
      setLayout(new BorderLayout());

      // 新增到容器中
      add(lb, BorderLayout.NORTH);
      add(bt, BorderLayout.SOUTH);
   }
}