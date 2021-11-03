import com.fasterxml.jackson.core.JsonParser;
import com.fasterxml.jackson.databind.ObjectMapper;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.util.HashMap;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class TodoList {
    private Integer id;
    private String time, content;
    public TodoList(int id, String time, String content) {
        this.id=id;
        this.time=time;
        this.content=content;
    }

    public Integer getId() {
        return id;
    }

    public String getContent() {
        return content;
    }

    public String getTime() {
        return time;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public void setTime(String time) {
        this.time = time;
    }

    public void setContent(String content) {
        this.content = content;
    }
}

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

        // addButton 눌러서 일정 추가 & 일정 불러오기
        addButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // 1. POST - DB에 일정 추가
                String time = timeText.getText();
                String content = contentText.getText();

//                // json으로 전달할 내용 객체로 저장
//                var values = new HashMap<String, String>() {{
//                    put("time", time);
//                    put("content", content);
//                }};
//
//                // 발생하는 exception을 처리하기 위해 try-catch문 사용
//                try {
//                    var objectMapper = new ObjectMapper();
//                    // 위에서 저장된 객체 json으로 변환해서 저장
//                    String requestBody = objectMapper.writeValueAsString(values);
//                    System.out.println(requestBody);
//
//                    HttpClient client = HttpClient.newHttpClient();
//                    HttpRequest request = HttpRequest.newBuilder()
//                            .uri(URI.create("http://localhost:8080/add"))  // 요청을 보낼 주소
//                            .header("Content-Type", "application/json; charset=UTF-8")  // content type, 인코딩형식 지정
//                            .POST(HttpRequest.BodyPublishers.ofString(requestBody))  // 전달할 json 지정
//                            .build();
//
//                    // response 저장
//                    HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());
//                    System.out.println(response.body());
//                }
//                catch (Exception error) {
//                    System.out.println("오류 발생");
//                };

                // 2. 테이블 초기화
                dtm.setRowCount(0);

                // 3. GET - DB에서 일정 로드, 테이블 구성.
                try {
                    HttpClient client = HttpClient.newHttpClient();
                    // IOException, InterruptedException 처리 필요.
                    HttpRequest request = HttpRequest.newBuilder()
                            .uri(URI.create("http://localhost:8080/all"))  // 요청을 보낼 주소
                            .build();

                    // response 저장
                    HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());

                    // response.body()에 들어있는 json array 객체로 변환
                    ObjectMapper mapper = new ObjectMapper();
                   Map<String, String>[] M = mapper.readValue(response.body(), Map[].class);
                    for(Map<String, String> m : M) {
                        dtm.addRow(new Object[] {m.get("time"), m.get("content")});
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
