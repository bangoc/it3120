import java.util.Optional;
import java.util.stream.Stream;

public interface CustomerDAO {
  public Stream<Customer> getAll() throws Exception;
  public Optional<Customer> getById(int id) throws Exception;
  public boolean add(Customer customer) throws Exception;
  public boolean add(final int id, 
                     final String firstName, 
                     final String lastName) throws Exception;
  public boolean update(Customer customer) throws Exception;
  public boolean delete(Customer customer) throws Exception;
}
