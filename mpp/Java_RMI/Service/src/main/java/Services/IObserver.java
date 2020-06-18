package Services;

import Models.Caritate;

import java.io.Serializable;
import java.rmi.Remote;
import java.util.List;

public interface IObserver extends Remote {

    void notify(List<Caritate> list);

}
