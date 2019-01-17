
Vagrant.configure("2") do |config|

  config.vm.hostname = "ALignTechnology"
  config.vm.box = "hashicorp/boot2docker"

  config.vm.provision "docker" do |d|
    d.run"pabgo/qt_5.12.0_ubuntu18.04:v6", auto_assign_name: false,  args: "-it -p 8080:8080 --name DockerLocalMatch --hostname=Container "
  end

end
