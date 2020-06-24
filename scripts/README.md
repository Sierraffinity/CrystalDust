# Automated Build Scripts

I'll add to this later, but here's the 411...

## Docker Setup
1. Install docker, obviously...
2. `cd scripts/docker_build`
3. `./run_docker.bat/sh I'm not gonna judge`

Once in the container (bash will start with `/source`)
1. `cd scripts`
2. If you haven't run it before, `./init_dev_environment.sh`
3. `build.sh`