import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class TodoListGUI extends JFrame {
    private JPanel mainPanel;
    private JLabel title;
    private JTextField timeText;
    private JTextField contentText;
    private JButton addButton;
    private JTable todoTable;
    private JButton delButton;

    public TodoListGUI(String title) {
        super(title);

        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setContentPane(mainPanel);

        DefaultTableModel dtm = new DefaultTableModel(0, 0);
        String[] header = {"time", "Content"};
        dtm.setColumnIdentifiers(header);
        todoTable.setModel(dtm);

        this.pack();

        addButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String name = timeText.getText();
                String content = contentText.getText();
                dtm.addRow(new Object[] {name, content});
            }
        });

        delButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                //Delete Selected Row
                int getSelectedRowForDeletion = todoTable.getSelectedRow();
                //Check if their is a row selected
                if (getSelectedRowForDeletion >= 0) {
                    dtm.removeRow(getSelectedRowForDeletion);
                    JOptionPane.showMessageDialog(null, "Row Deleted");
                } else {
                    JOptionPane.showMessageDialog(null, "Unable To Delete");
                }
            }
        });
    }

    public static void main(String[] args) {
        JFrame frame = new TodoListGUI("TODO list");
        frame.setVisible(true);
    }
}
