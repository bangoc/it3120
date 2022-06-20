import java.sql.Connection;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Stream;

import javax.sql.DataSource;

import org.h2.jdbcx.JdbcDataSource;

public class App {
  private static final String DB_URL = "jdbc:h2:~/tmp/h2db";

  public static void main(final String[] args) throws Exception {
    final DataSource dataSource = createDataSource();
    createSchema(dataSource);
    final CustomerDAO customerDAO = new H2CustomerDAO(dataSource);
    customerDAO.add(1, "Nguyen", "Van A");
    customerDAO.add(2, "Tran", "Thi B");
    customerDAO.add(3, "Bui", "Xuan C");
    System.out.println("customerDAO.getAllCustomers(): ");
    try (Stream<Customer> customerStream = customerDAO.getAll()) {
      customerStream.forEach((customer) -> System.out.println(customer));
    }
    System.out.println("customerDAO.getCustomerById(2): " + customerDAO.getById(2));
    final Customer customer = new Customer(4, "Vo", "Van D");
    customerDAO.add(customer);
    System.out.println("customerDAO.getAllCustomers(): " + customerDAO.getAll());
    customer.setFirstName("La");
    customer.setLastName("Van F");
    customerDAO.update(customer);
    System.out.println("customerDAO.getAllCustomers(): ");
    try (Stream<Customer> customerStream = customerDAO.getAll()) {
      customerStream.forEach((cust) -> System.out.println(cust));
    }
    customerDAO.delete(customer);
    System.out.println("customerDAO.getAllCustomers(): " + customerDAO.getAll());
    deleteSchema(dataSource);
  }

  private static void deleteSchema(DataSource dataSource) throws SQLException {
    try (Connection connection = dataSource.getConnection();
        Statement statement = connection.createStatement()) {
      statement.execute(CustomerSchemaSql.DELETE_SCHEMA_SQL);
    }
  }

  private static void createSchema(DataSource dataSource) throws SQLException {
    try (Connection connection = dataSource.getConnection();
        Statement statement = connection.createStatement()) {
      statement.execute(CustomerSchemaSql.CREATE_SCHEMA_SQL);
    }
  }

  private static DataSource createDataSource() {
    JdbcDataSource dataSource = new JdbcDataSource();
    dataSource.setURL(DB_URL);
    return dataSource;
  }
}
