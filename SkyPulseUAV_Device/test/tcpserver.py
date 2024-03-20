import socket

# 服务器地址和端口
HOST = '192.168.170.30'  # 监听所有网络接口
PORT = 8080

# 创建一个 TCP 套接字
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server_socket:
    # 将套接字绑定到指定的地址和端口
    server_socket.bind((HOST, PORT))
    # 开始监听连接
    server_socket.listen()

    print(f"Server listening on {HOST}:{PORT}")

    # 接受连接并处理消息
    while True:
        # 接受客户端连接
        client_socket, client_address = server_socket.accept()
        print(f"Connected to {client_address}")

        # 在这里添加你想要打印的消息
        print("Client connected successfully!")

        with client_socket:
            # 接收来自客户端的消息
            data = client_socket.recv(1024)
            if data:
                print(f"Received message: {data.decode()}")
                # 在这里可以添加其他处理逻辑
            else:
                print("Client disconnected")