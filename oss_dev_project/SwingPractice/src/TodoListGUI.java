import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

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

        // addButton을 눌러서 일정 추가

        // 2. GET - DB에서 일정 로드

        addButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // 1. POST - DB에 일정 추가
//                String name = timeText.getText();
//                String content = contentText.getText();

                // 2. 테이블 초기화
                dtm.setRowCount(0);

                // 3. GET - DB에서 일정 로드, 테이블 구성.
                HttpClient client = HttpClient.newHttpClient();
                HttpRequest request = HttpRequest.newBuilder()
                        .uri(URI.create("http://localhost:8080/all"))
                        .build();
                try {
                    // IOException, InterruptedException 처리 필요.
                    HttpResponse<String> response = client.send(request,
                            HttpResponse.BodyHandlers.ofString());

                    // JSON으로 변환해서 사용하려면 추가적으로 라이브러리를 다운해야 하는 것 같다.
                    // 정규식 사용해서 데이터만 뽑아보자.
                    Pattern p = Pattern.compile("(\\{\"id\":\"?([^,\"]+)\"?,\"time\":\"?([^,\"]+)\"?,\"content\":\"?([^,\"]+)\"?\\})");
                    Matcher m = p.matcher(response.body());
                    while(m.find()) {
                        String id = m.group(2);
                        String time = m.group(3);
                        String content = m.group(4);
                        dtm.addRow(new Object[] {time, content});
                    }
                }
                catch (Exception error) {
                    System.out.println("오류 발생");
                };
            }
        });

        // DB 연동은 보류.
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
