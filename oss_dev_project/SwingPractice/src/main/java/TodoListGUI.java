import com.fasterxml.jackson.core.JsonParser;
import com.fasterxml.jackson.databind.ObjectMapper;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import javax.swing.table.TableColumnModel;
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

public class TodoListGUI extends JFrame {
    private JPanel mainPanel;
    private JLabel title;
    private JTextField timeText;
    private JTextField contentText;
    private JButton addButton;
    private JTable todoTable;
    private JButton delButton;
    private JButton editButton;

    // 일정 읽어오기
    void getTodoList(DefaultTableModel dtm) {
        // 1. 테이블 초기화
        dtm.setRowCount(0);


        // 2. GET - DB에서 일정 로드, 테이블 구성.
        try {
            HttpClient client = HttpClient.newHttpClient();
            // IOException, InterruptedException 처리 필요.
            HttpRequest request = HttpRequest.newBuilder()
                    .uri(URI.create("http://localhost:8080"))  // 요청을 보낼 주소
                    .GET()
                    .build();


            // response 저장
            HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());

            // response.body()에 들어있는 json array -> 객체로 변환
            ObjectMapper mapper = new ObjectMapper();
            Map<String, String>[] M = mapper.readValue(response.body(), Map[].class);
            for(Map<String, String> m : M) {
                // Jtable에 일정 추가
                dtm.addRow(new Object[] {m.get("id"), m.get("time"), m.get("content")});
            }
        }
        catch (Exception error) {
            System.out.println("오류 발생");
        };
    };

    public TodoListGUI(String title) {
        super(title);

        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setContentPane(mainPanel);

        DefaultTableModel dtm = new DefaultTableModel(0, 0);
        String[] header = {"id", "time", "Content"};
        dtm.setColumnIdentifiers(header);
        todoTable.setModel(dtm);
        // id는 안보이게 설정
        todoTable.removeColumn(todoTable.getColumnModel().getColumn(0));

        getTodoList(dtm);

        this.pack();

        // 일정 추가
        addButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // 발생하는 exception을 처리하기 위해 try-catch문 사용
                try {
                    String uri = "http://localhost:8080"; // 요청 보낼 주소
                    // URI RequestParam 추가
                    uri = uri+"?time="+timeText.getText()+"&content="+contentText.getText();

                    HttpClient client = HttpClient.newHttpClient();
                    HttpRequest request = HttpRequest.newBuilder()
                            .uri(URI.create(uri))  // 위에서 만든 uri
                            .POST(HttpRequest.BodyPublishers.noBody())
                            .build();

                    // response 저장
                    HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());
                    System.out.println(response.body());
                }
                catch (Exception error) {
                    System.out.println("오류 발생");
                };

                getTodoList(dtm);
            }
        });

        // 일정 삭제
        delButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                //Delete Selected Row
                int delRow = todoTable.getSelectedRow();
                //Check if their is a row selected
                if (delRow >= 0) {
                    int delId = (int)todoTable.getModel().getValueAt(delRow, 0);
                    String uri = "http://localhost:8080"; // 요청을 보낼 주소
                    // URI PathVariable 추가
                    uri = uri+"/"+Integer.toString(delId);

                    // 발생하는 exception을 처리하기 위해 try-catch문 사용
                    try {
                        HttpClient client = HttpClient.newHttpClient();
                        HttpRequest request = HttpRequest.newBuilder()
                                .uri(URI.create(uri))  // 위에서 만든 uri
                                .DELETE()  // 전달할 json 지정
                                .build();

                        // response 저장
                        HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());
                        System.out.println(response.body());
                    }
                    catch (Exception error) {
                        System.out.println("오류 발생");
                    };

                    getTodoList(dtm);
                    JOptionPane.showMessageDialog(null, "Row Deleted");
                } else {
                    JOptionPane.showMessageDialog(null, "Unable To Delete");
                }
            }
        });

        // 일정 수정
        editButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                //Edit Selected Row
                int editRow = todoTable.getSelectedRow();
                //Check if their is a row selected
                if (editRow >= 0) {
                    int editId = (int)todoTable.getModel().getValueAt(editRow, 0);
                    String uri = "http://localhost:8080"; // 요청 보낼 주소
                    // URI PathVariable 추가
                    uri = uri+"/"+Integer.toString(editId);

                    // json으로 전달할 내용 객체로 저장
                    var values = new HashMap<String, String>() {{
                        put("time", timeText.getText());
                        put("content", contentText.getText());
                    }};

                    // 발생하는 exception을 처리하기 위해 try-catch문 사용
                    try {
                        var objectMapper = new ObjectMapper();
                        // 위에서 저장된 객체 json으로 변환해서 저장
                        String requestBody = objectMapper.writeValueAsString(values);

                        HttpClient client = HttpClient.newHttpClient();
                        HttpRequest request = HttpRequest.newBuilder()
                                .uri(URI.create(uri))  // 위에서 만든 uri
                                .header("Content-Type", "application/json; charset=UTF-8")  // content type, 인코딩형식 지정
                                .PUT(HttpRequest.BodyPublishers.ofString(requestBody)) // 전달할 json 지정
                                .build();

                        // response 저장
                        HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());
                        System.out.println(response.body());
                    }
                    catch (Exception error) {
                        System.out.println("오류 발생");
                    };

                    getTodoList(dtm);
                    JOptionPane.showMessageDialog(null, "Edited");
                } else {
                    JOptionPane.showMessageDialog(null, "Unable To Edit");
                }
            }
        });
    }

    public static void main(String[] args) {
        JFrame frame = new TodoListGUI("TODO list");
        frame.setVisible(true);
    }
}
