﻿using System;
using System.ServiceProcess;

namespace WinBtrfsService
{
	public partial class Service : ServiceBase
	{
		public Service()
		{
			InitializeComponent();
		}

		protected override void OnStart(string[] args)
		{

		}

		protected override void OnStop()
		{

		}
	}
}
