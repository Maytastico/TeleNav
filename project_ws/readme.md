# Einrichtung 🛠️

Um dieses Projekt nutzen zu können, benötigst du:

  * **ROS 2 Humble** auf **Ubuntu 22.04.5 LTS**.
  * Folgende Python-Pakete:
      * `flask`
      * `scipy`
      * `numpy`

Alle erforderlichen Pakete kannst du ganz einfach über das Skript `bash setup_packages.sh` im Stammverzeichnis des Repositories installieren.

-----

# Ausführen 🚀

1.  Richte zuerst die ROS 2-Umgebung ein, indem du die Datei `install/setup.bash` lädst:
    ```bash
    source install/setup.bash
    ```
2.  Starte anschließend die Simulation mit:
    ```bash
    ros2 launch telerobot_bringup telerobo_simple.xml
    ```
3.  Danach starte die Webschnittstelle:
    ```bash
    ros2 run telerobot_controller interface
    ```
4.  Zum Schluss starte den Controller:
    ```bash
    ros2 run telerobot_controller controller
    ```

Die Webschnittstelle ist nun unter **127.0.0.1:5000** erreichbar.

> **Hinweis:** Der Controller kann abstürzen, da ein bekannter ROS 2-Fehler mit dem Reichweitensensor auftritt, der dazu führt, dass **NaN**-Werte zurückgegeben werden. Bisher gibt es keine bekannte Lösung für dieses Problem. 🐞

-----

# Benutzung 🎮

Du kannst den Roboter entweder über die Tastatur oder mit der Maus steuern.

### Tastatursteuerung ⌨️

  * **W:** Vorwärts
  * **S:** Rückwärts
  * **D:** Nach rechts drehen
  * **A:** Nach links drehen
  * **Leertaste:** Anhalten

### Maussteuerung 🖱️

Bewege den grünen Kreis in die gewünschte Richtung, um den Roboter zu steuern.

-----

# Entwicklung 💻

Nachdem du die Umgebung des Projekts (`project_ws`) eingerichtet hast, führe `code .` aus, um Visual Studio Code zu starten.