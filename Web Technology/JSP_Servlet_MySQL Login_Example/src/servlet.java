import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.*;
import javax.servlet.annotation.WebServlet;

@WebServlet("/login")
public class servlet extends HttpServlet {
    private static final long serialVersionUID = 1L;
    private loginConnect conn;

    public void init() {
    	conn = new loginConnect();
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, IOException {

        String username = request.getParameter("username");
        String password = request.getParameter("password");
        gettersetter gtrstr = new gettersetter();
        gtrstr.setUsername(username);
        gtrstr.setPassword(password);

        try {
            if (conn.validate(gtrstr)) {
               response.sendRedirect("loginsuccess.jsp");
            } else {
                HttpSession session = request.getSession();
                response.sendRedirect("login.jsp");
            }
        } catch (ClassNotFoundException e) {
        	response.sendRedirect("login.jsp");
            e.printStackTrace();
        }
    }
}