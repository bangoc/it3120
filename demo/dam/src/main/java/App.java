import java.sql.Connection;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Stream;

import javax.sql.DataSource;

import org.h2.jdbcx.JdbcDataSource;

public class App {
  private static final String DB_URL = "jdbc:h2:~/tmp";

  public static void main(final String[] args) throws Exception {
    final DataSource dataSource = createDataSource();
    createSchema(dataSource);
    final CustomerDAM customerDAM = new CustomerDAM(dataSource);
    customerDAM.add(1, "Nguyen", "Van A");
    customerDAM.add(2, "Tran", "Thi B");
    customerDAM.add(3, "Bui", "Xuan C");
    System.out.println("customerDAM.getAllCustomers(): ");
    try (Stream<Customer> customerStream = customerDAM.getAll()) {
      customerStream.forEach((customer) -> System.out.println(customer));
    }
    System.out.println("customerDAM.getCustomerById(2): " + customerDAM.getById(2));
    final Customer customer = new Customer(4, "Vo", "Van D");
    customerDAM.add(customer);
    System.out.println("customerDAM.getAllCustomers(): " + customerDAM.getAll());
    customer.setFirstName("La");
    customer.setLastName("Van F");
    customerDAM.update(customer);
    System.out.println("customerDAM.getAllCustomers(): ");
    try (Stream<Customer> customerStream = customerDAM.getAll()) {
      customerStream.forEach((cust) -> System.out.println(cust));
    }
    customerDAM.delete(customer);
    System.out.println("customerDAM.getAllCustomers(): " + customerDAM.getAll());
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
