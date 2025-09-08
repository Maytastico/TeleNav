from setuptools import find_packages, setup
import glob

package_name = 'telerobot_controller'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/templates', glob.glob('templates/*')),
        ('share/' + package_name + '/static', glob.glob('static/*')),
        # Füge helpers-Ordner hinzu:
        ('lib/' + package_name + '/helpers', glob.glob('telerobot_controller/helpers/*')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='ros',
    maintainer_email='ros@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'controller = telerobot_controller.distance_messurement:main',
            'interface = telerobot_controller.interface:main'
        ],
    },
)
