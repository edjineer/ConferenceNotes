terraform {
  required_providers {
    aws = {
      source  = "hashicorp/aws"
      version = "~> 4.16"
    }
  }

  required_version = ">= 1.2.0"
}

provider "aws" {
  region = "ap-south-1"
}

resource "aws_instance" "app_server_EDJ" {
  ami           = "ami-02e1a4ebef29334f9"
  instance_type = "t2.micro"

  tags = {
    Name = var.instance_name
  }
}

output "instance_ip_address" {
  description = "The public IP address of the instance"
  value       = aws_instance.app_server_EDJ.public_ip
}