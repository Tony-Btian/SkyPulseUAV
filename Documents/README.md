#### 2.Writing Raspberry Pi OS System

##### Preparation

| Hardware       | Software                                              |
| -------------- | ----------------------------------------------------- |
| SD Card        | Raspberry Pi system writing tool: Raspberry Pi Imager |
| SD Card Reader |                                                       |

##### System Writing

Connect the SD card to the computer using a card reader, open the Raspberry Pi writing tool, select the appropriate Raspberry Pi model and system, as well as the SD storage card. The system will prioritize selecting the most recently released Raspberry Pi OS, usually with a recommended system. Debian has better hardware support, so here we take Debian as an example.
![[Pasted image 20240415010201.png]]
Before burning, you can choose to configure the Raspberry Pi OS system in advance. Alternatively, you can enter the system and make settings after burning is complete.
![[Pasted image 20240415010231.png]]
Here, taking early system setup as an example, click on 'Edit Settings'.
![[Pasted image 20240415010314.png]]

1. Set Hostname: [Hostname]
2. Set Username and Password
3. Configure Wi-Fi: Here, the Wi-Fi list will not be displayed. You need to directly enter the SSID of the Wi-Fi (the name displayed in the Wi-Fi list).
4. Language and Timezone Settings

After completing the above settings, click on 'SERVICES', check 'Enable SSH service', and choose to log in using a password. The password here is the username and password set earlier.
![[Pasted image 20240415010430.png]]
Click 'Save' to begin writing the system.
![[Pasted image 20240415010454.png]]
After burning is complete, simply insert the SD card into the Raspberry Pi. Upon powering on, the system will initialize automatically.
If the system was configured in advance, it will directly enter the desktop.
If no prior setup was done, a simple system boot configuration will guide you into the desktop.
External display devices can be connected to the Raspberry Pi via HDMI.

\*Note: Each system burning process will format the SD card, so it's important to back up the data on the SD card before burning.

##### System Upgrade

Once the system is loaded, enter the desktop. The Raspberry Pi desktop looks like this:"
![[Pasted image 20240415010608.png]]
The first thing to do after system installation is to upgrade the system. Open the terminal and type:

```
sudo apt-get update
sudo apt-get upgrade
```

\*Note: If prompted with (Y/N) during the upgrade process, type Y and press Enter. The initial upgrade may take a considerable amount of time, so please be patient.

#### Remote Connection to Raspberry Pi

Connecting the Raspberry Pi to a screen via HDMI can be cumbersome, so you can connect to it remotely using remote desktop.

##### SSH Connection

SSH is an encrypted remote connection network protocol primarily used for remote management of systems and servers. SSH connections ensure secure and confidential data transmission between two devices through public key encryption. Once established, SSH executes commands via the command line, enabling remote control of the device, particularly when the target device is a Linux system.

There are two methods to enable SSH service on the Raspberry Pi:

1. Enabling SSH via the graphical interface.
2. Enabling SSH via the command line.

##### Enabling SSH via the graphical interface:

Click on 'Menu' ➡️ 'Preferences' ➡️ 'Raspberry Pi Configuration', as shown in the following figure:
![[Pasted image 20240415011325.png]]
Turn on the SSH switch, and it is recommended to turn all switches on.
![[Pasted image 20240415011349.png]]

##### configure via the command line

Enter the following in the terminal

```
sudo raspi-config
```

Select Interface Options -> SSH to enable SSH, as shown in the following figure:
![[Pasted image 20240415011706.png]]
To connect via SSH from another host, taking macOS system as an example (the instructions for Windows are the same), enter the following in the macOS terminal:

```
ssh username@ip_address
```

![[Pasted image 20240415011744.png]]
When prompted to establish the connection, type 'yes' and then press Enter. Next, enter the password to establish the SSH connection. The password is the same as the login password for the Raspberry Pi.
![[Pasted image 20240415011835.png]]
If the following screen appears during the connection process:
![[Pasted image 20240415011920.png]]
Then you need to input

```
ssh-keygen -R <Host_IP>
```

This is because the key received by the target device for the SSH connection request does not match the key stored on the device. For security reasons, SSH clients do not connect to hosts with mismatched keys by default. The above command is used to reconnect SSH, prompting the host to create a new key.

#### VNC Connection

VNC connection provides a visual remote desktop connection service, allowing developers to operate the Raspberry Pi directly through a graphical interface. To connect to the Raspberry Pi via VNC, you need to download VNC software: RealVNC.

\*We have already enabled the VNC service when setting up the SSH connection. If the connection is unsuccessful, please check if the VNC service is enabled.
![[Pasted image 20240415012101.png]]

Simply enter the IP address of the Raspberry Pi, fill in the username and password, and you will be able to connect to the Raspberry Pi's remote desktop via VNC.
![[Pasted image 20240415012136.png]]
