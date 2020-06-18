package Proxy;

import IService.IServiceUser;
import Models.Caritate;
import Service.ServiceUser;
import Utils.Response;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.List;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingDeque;

public class ResponseReader {

    private ObjectInputStream input;
    private ObjectOutputStream output;
    private Socket connection;
    private boolean finished;
    private IServiceUser serviceUser;
    private BlockingQueue<Response> queue;

    public ResponseReader(ObjectInputStream input, ObjectOutputStream output, Socket connection) {
        this.input = input;
        this.output = output;
        this.connection = connection;
        this.finished = false;
        queue = new LinkedBlockingDeque<>();
    }

    public void setServiceUser(IServiceUser iServiceUser) {
        this.serviceUser = iServiceUser;
    }

    public Response readResponse() {
        Response response = null;

        try {
            System.out.println("Citire raspuns ... ");
            response = queue.take();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        return response;
    }

    public void logOut() {
        this.finished = true;
    }

    public void startReader(){
        Thread tw = new Thread(new ReaderThread());
        tw.start();
    }

    private class ReaderThread implements Runnable {
        public void run() {
            while(!finished) {
                System.out.println("Citire raspunsuri ... ");

                try {
                    Object response = input.readObject();
                    Response finalResponse = (Response) response;

                    System.out.println("Raspuns primit ... ");

                    if(finalResponse.getMesaj().equals("getNotified"))
                        serviceUser.notifyClients((List<Caritate>) finalResponse.getListCaritate());
                    else {
                        try {
                            queue.put(finalResponse);
                        }
                        catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                } catch (ClassNotFoundException e) {
                    e.printStackTrace();
                }
            }
        }
    }

}
